#include "include/InnerProductProofVerifier.h"

namespace bulletproofs {

InnerProductProofVerifier::InnerProductProofVerifier(
        const GeneratorVector& g,
        const GeneratorVector& h,
        const GroupElement& u,
        const GroupElement& P)
        : g_(g)
        , h_(h)
        , u_(u)
        , P_(P)
{
}

bool InnerProductProofVerifier::verify(const InnerProductProof& proof){
    auto itr_l = proof.l_begin();
    auto itr_r = proof.r_begin();
    Scalar x = get_x(P_);
    P_ = P_ + u_ * x * proof.get_c();
    return verifyUtil(proof, itr_l, itr_r);
}

bool InnerProductProofVerifier::verifyUtil(
                                           const InnerProductProof& proof,
                                           std::vector<GroupElement>::const_iterator itr_l,
                                           std::vector<GroupElement>::const_iterator itr_r){
    if((itr_l + 1) == proof.l_end()){
        Scalar c = proof.get_a() * proof.get_b();
        return P_ == g_ * proof.get_a() + h_ * proof.get_b() + u_ * c;
    }

    //Get challenge x
    Scalar x = get_x(*itr_l, *itr_r);
    //Compute g prime and p prime
    GeneratorVector g_p = g_prime(x);
    GeneratorVector h_p = h_prime(x);
    //Compute P prime
    GroupElement p_p = p_prime(*itr_l, *itr_r, x);
    return InnerProductProofVerifier(g_p, h_p, u_, p_p).verifyUtil(proof, ++itr_l, ++itr_r);
}

GeneratorVector InnerProductProoveGenerator::g_prime(const Scalar& x){
    std::vector<GroupElement> g;
    for(int i = 0; i < g_.size() / 2; ++i){
        g.push_back(g_.get_g(g_.size() / 2  + i) * x.inverse() + g_.get_g(i) * x);
    }
    return  GeneratorVector(g);
}

GeneratorVector InnerProductProoveGenerator::h_prime(const Scalar& x){
    std::vector<GroupElement> h;
    for(int i = 0; i < g_.size() / 2; ++i){
        h.push_back(h_.get_g(h_.size() / 2  + i) * x + h_.get_g(i) * x.inverse());
    }
    return  GeneratorVector(h);
}

GroupElement InnerProductProoveGenerator::p_prime(const GroupElement& L,const GroupElement& R, const Scalar& x){
    return L * (x.square()) + P_ + R * (x.square().inverse());
}

}// namespace bulletproofs