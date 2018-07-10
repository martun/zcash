#include "include/InnerProductProoveGenerator.h"


namespace bulletproofs {

InnerProductProoveGenerator::InnerProductProoveGenerator(
        const GeneratorVector& g,
        const GeneratorVector& h,
        const GroupElement& u,
        const GroupElement& P)
    : g_(g)
    , h_(h)
    , u_(u)
    , P(P)
{

}

void InnerProductProoveGenerator::generate_proof(
        const std::vector<Scalar>& a,
        const std::vector<Scalar>& b,
        InnerProductProof& proof_out) {
    Scalar x = get_x(P_);
    const Scalar c = scalar_dot_product(a.begin(), a.end(), b.begin(), b.end());
    proof_out.set_c(c);
    P_ = P + u_ * (x*c);
    generate_proof_util(a, b, proof_out);
}

void InnerProductProoveGenerator::generate_proof_util(
            const std::vector<Scalar>& a,
            const std::vector<Scalar>& b,
            InnerProductProof& proof_out) {

    if(a.size() == 1 && b.size() == 1){ //Protocol 2 line 15
        proof_out.set_a(a[0]);
        proof_out.set_b(b[0]);
        return;
    }

    int n = a.size() / 2;
    // Computes cL then L
    Scalar cL = scalar_dot_product(a.begin() + n, a.end(), b.begin(), b.begin() + n);
    GroupElement L;
    l(a.begin() + n, a.end(), b.begin(), b.begin() + n, cL, L);
    //Computes cR then R
    Scalar cR = scalar_dot_product(a.begin(), a.begin() + n, b.begin() + n, b.end());
    GroupElement R;
    r(a.begin(), a.begin() + n, b.begin() + n, b.end(), cR, R);
    //Push L and R
    proof_out.push_l(L);
    proof_out.push_r(R);
    //Get challenge x
    Scalar x = get_x(L, R);
    //Compute g prime and p prime
    GeneratorVector g_p = g_prime(x);
    GeneratorVector h_p = h_prime(x);
    //Compute a prime and b prime
    std::vector<Scalar> a_p = a_prime(x, a);
    std::vector<Scalar> b_p = b_prime(x, b);
    //Compute P prime
    GroupElement p_p = p_prime(L, R, x);
    // Recursive call of protocol 2
    InnerProductProoveGenerator(g_p, h_p, u_, p_p).generate_proof(a_p, b_p, proof_out);
}


void InnerProductProoveGenerator::hash(
        std::vector<Scalar>::const_iterator& a1_start,
        std::vector<Scalar>::const_iterator& a1_end,
        std::vector<Scalar>::const_iterator& a2_start,
        std::vector<Scalar>::const_iterator& a2_end,
        std::vector<Scalar>::const_iterator& b1_start,
        std::vector<Scalar>::const_iterator& b1_end,
        std::vector<Scalar>::const_iterator& b2_start,
        std::vector<Scalar>::const_iterator& b2_end,
        const Scalar& c,
        GroupElement& result_out) {
    GroupElement g1, g2, h1, h2, uc;

    g_.get_vector_multiple(g_.size() / 2 + 1, g_.size(), a1_start, a1_end, g1);
    g_.get_vector_multiple(0, g_.size()/2 + 1, a2_start, a2_end, g2);

    h_.get_vector_multiple(h_.size() / 2 + 1, h_.size(), b1_start, b1_end, h1);
    h_.get_vector_multiple(0, h_.size() / 2 + 1, b2_start, b2_end, h2);

    uc = u_ * c;

    result_out = g1 + g2 + h1 + h2 + uc;
}


void InnerProductProoveGenerator::l(
        std::vector<Scalar>::const_iterator a_start,
        std::vector<Scalar>::const_iterator a_end,
        std::vector<Scalar>::const_iterator b_start,
        std::vector<Scalar>::const_iterator b_end,
        const Scalar& cL,
        GroupElement& result_out) {
    GroupElement g, h, ucL;

    g_.get_vector_multiple(0, g_.size() / 2 + 1, a_start, a_end, g);
    h_.get_vector_multiple(h_.size() / 2 + 1 , h_.size(), b_start, b_end, h);
    ucL = u_ * cL;

    result_out = g + h + ucL;
}

void InnerProductProoveGenerator::r(
       std::vector<Scalar>::const_iterator a_start,
       std::vector<Scalar>::const_iterator a_end,
       std::vector<Scalar>::const_iterator b_start,
       std::vector<Scalar>::const_iterator b_end,
       const Scalar& cR,
       GroupElement& result_out) {
    GroupElement g, h, ucR;

    g_.get_vector_multiple(g_.size() / 2 + 1, g_.size(), a_start, a_end, g);
    h_.get_vector_multiple(0, h_.size() / 2 + 1, b_start, b_end, h);
    ucR = u_ * cR;
    result_out = g + h + ucR;
}



std::vector<Scalar> InnerProductProoveGenerator::a_prime(const Scalar& x, const std::vector<Scalar>& a){
    std::vector<Scalar> result;
    result.reserve(a.size() / 2);
    for(int i = 0; i < a.size() / 2; ++i){
        result.push_back(a[a.size() / 2 + i] * x + a[i] * x.inverse());
    }
    return  result;
}

std::vector<Scalar> InnerProductProoveGenerator::b_prime(const Scalar& x, const std::vector<Scalar>& b){
    std::vector<Scalar> result;
    result.reserve(b.size() / 2);
    for(int i = 0; i < b.size() / 2; ++i){
        result.push_back(b[b.size() / 2 + i] * x + b[i] * x.inverse());
    }
    return  result;
}

GroupElement InnerProductProoveGenerator::p_prime(const GroupElement& L,const GroupElement& R, const Scalar& x){
    return L * (x.square()) + P_ + R * (x.square().inverse());
}

} // namespace bulletproofs
