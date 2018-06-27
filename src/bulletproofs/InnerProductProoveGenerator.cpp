#include "InnerProductProoveGenerator.h"

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

}


