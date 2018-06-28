#include "InnerProductProoveGenerator.h"


namespace bulletproofs {

InnerProductProoveGenerator::InnerProductProoveGenerator(
        const GerneratorPrecomputedStorage& g,
        const GerneratorPrecomputedStorage& h,
        const secp256k1_ge& u,
        const secp256k1_ge& P)
    : g_(g)
    , h_(h)
    , u_(u)
    , P_(P)
{

}

void InnerProductProoveGenerator::generate_proof(
            const std::vector<secp256k1_scalar> &a,
            const std::vector<secp256k1_scalar> &b,
            InnerProductProof& proof_out) {

}


void InnerProductProoveGenerator::hash(
        const std::vector<secp256k1_scalar>::const_iterator& a1_start,
        const std::vector<secp256k1_scalar>::const_iterator& a1_end,
        const std::vector<secp256k1_scalar>::const_iterator& a2_start,
        const std::vector<secp256k1_scalar>::const_iterator& a2_end,
        const std::vector<secp256k1_scalar>::const_iterator& b1_start,
        const std::vector<secp256k1_scalar>::const_iterator& b1_end,
        const std::vector<secp256k1_scalar>::const_iterator& b2_start,
        const std::vector<secp256k1_scalar>::const_iterator& b2_end,
        const secp256k1_scalar& c,
        secp256k1_ge& result_out) {

    secp256k1_ge  g1, g2, h1, h2, uc;

    g_.get_vector_multiply(g_.size()/2 + 1, g.size(), a1_start, a1_end, g1);
    g_.get_vector_multiply(0, g_.size()/2 + 1, a2_start, a2_end, g2);

    h_.get_vector_multiply(h_.size()/2 + 1, h.size(), b1_start, b1_end, h1);
    h_.get_vector_multiply(0, h_.size()/2 + 1, b2_start, b2_end, h2);

    secp256k1_ecmult_const(&uc, &u_, &c);

    secp256k1_gej result_jacobian;
    secp256k1_gej_add_ge(&result, &result, &g1);
    secp256k1_gej_add_ge(&result, &result, &g2);
    secp256k1_gej_add_ge(&result, &result, &h1);
    secp256k1_gej_add_ge(&result, &result, &h2);
    secp256k1_gej_add_ge(&result, &result, &uc);

    secp256k1_ge_set_gej(&result_out, &result_jacobian);
}


void l(const std::vector<secp256k1_scalar>::const_iterator& a_start,
        const std::vector<secp256k1_scalar>::const_iterator& a_end,
        const std::vector<secp256k1_scalar>::const_iterator& b_start,
        const std::vector<secp256k1_scalar>::const_iterator& b_end,
        const secp256k1_scalar& cL,
        secp256k1_ge& result_out) {

    secp256k1_ge  g, h, ucL;

    g_.get_vector_multiply(0, g_.size()/2 + 1, a_start, a_end, g);

    h_.get_vector_multiply(h_.size()/2 + 1 , h.size(), b_start, b_end, h);
    secp256k1_ecmult_const(&ucL, &u_, &cL);

    secp256k1_gej result_jacobian;
    secp256k1_gej_add_ge(&result, &result, &g);
    secp256k1_gej_add_ge(&result, &result, &h);
    secp256k1_gej_add_ge(&result, &result, &ucL);

    secp256k1_ge_set_gej(&result_out, &result_jacobian);
}

void r( const std::vector<secp256k1_scalar>::const_iterator& a_start,
        const std::vector<secp256k1_scalar>::const_iterator& a_end,
        const std::vector<secp256k1_scalar>::const_iterator& b_start,
        const std::vector<secp256k1_scalar>::const_iterator& b_end,
        const secp256k1_scalar& cR,
        secp256k1_ge& result_out){

    secp256k1_ge  g, h , ucR;

    g_.get_vector_multiply(g_.size()/2 + 1, g.size(), a_start, a_end, g);

    h_.get_vector_multiply(0, h_.size()/2 + 1, b_start, b_end, h);

    secp256k1_ecmult_const(&uR, &u_, &cR);

    secp256k1_gej result_jacobian;
    secp256k1_gej_add_ge(&result, &result, &g);
    secp256k1_gej_add_ge(&result, &result, &h);
    secp256k1_gej_add_ge(&result, &result, &ucR);

    secp256k1_ge_set_gej(&result_out, &result_jacobian);
}
} // namespace bulletproofs
