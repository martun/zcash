#ifndef ZCASH_INNERPRODUCTPROOVER_H
#define ZCASH_INNERPRODUCTPROOVER_H

#include <iostream>
#include <vector>
#include "secp256k1/src/group.h"
#include "secp256k1/src/scalar.h"
#include "secp256k1/src/ecmult.h"
#include "secp256k1/src//scalar_4x64.h"

class InnerProductProoveGenerator {
    InnerProductProoveGenerator(
            const GerneratorVector& g,
            const GerneratorVector& h,
            const secp256k1_ge& u,
            const secp256k1_ge& P);

    void generate_proof(
            const std::vector<secp256k1_scalar> &a,
            const std::vector<secp256k1_scalar> &b,
            InnerProductProof& proof_out);

    void hash(
            const std::vector<secp256k1_scalar>::const_iterator& a1_start,
            const std::vector<secp256k1_scalar>::const_iterator& a1_end,
            const std::vector<secp256k1_scalar>::const_iterator& a2_start,
            const std::vector<secp256k1_scalar>::const_iterator& a2_end,
            const std::vector<secp256k1_scalar>::const_iterator& b1_start,
            const std::vector<secp256k1_scalar>::const_iterator& b1_end,
            const std::vector<secp256k1_scalar>::const_iterator& b2_start,
            const std::vector<secp256k1_scalar>::const_iterator& b2_end,
            const secp256k1_scalar& c,
            secp256k1_ge& result_out);

private:
    const GerneratorVector& g_;
    const GerneratorVector& h_;
    const secp256k1_ge& u_;
    const secp256k1_ge& P_;

};

#endif //ZCASH_INNERPRODUCTPROOVER_H
