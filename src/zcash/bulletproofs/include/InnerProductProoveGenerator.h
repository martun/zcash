#ifndef ZCASH_INNERPRODUCTPROOFVERIFIER_H
#define ZCASH_INNERPRODUCTPROOFVERIFIER_H

#include <iostream>
#include <vector>
#include "GeneratorVector.h"
#include <secp256k1/include/Scalar.h>
#include <secp256k1/include/GroupElement.h>

namespace bulletproofs {

class InnerProductProoveGenerator {
    InnerProductProoveGenerator(
            const GeneratorVector& g,
            const GeneratorVector& h,
            const GroupElement& u,
            const GroupElement& P);

    void generate_proof(
        const std::vector<Scalar> &a,
        const std::vector<Scalar> &b,
        InnerProductProof& proof_out);

    void hash(std::vector<Scalar>::const_iterator& a1_start,
              std::vector<Scalar>::const_iterator& a1_end,
              std::vector<Scalar>::const_iterator& a2_start,
              std::vector<Scalar>::const_iterator& a2_end,
              std::vector<Scalar>::const_iterator& b1_start,
              std::vector<Scalar>::const_iterator& b1_end,
              std::vector<Scalar>::const_iterator& b2_start,
              std::vector<Scalar>::const_iterator& b2_end,
              const Scalar& c,
              GroupElement& result_out);

    void l(std::vector<Scalar>::const_iterator& a_start,
            std::vector<Scalar>::const_iterator& a_end,
            std::vector<Scalar>::const_iterator& b_start,
            std::vector<Scalar>::const_iterator& b_end,
            const Scalar& cL,
            GroupElement& result_out);

    void r(std::vector<Scalar>::const_iterator& a_start,
           std::vector<Scalar>::const_iterator& a_end,
           std::vector<Scalar>::const_iterator& b_start,
           std::vector<Scalar>::const_iterator& b_end,
           const Scalar& cR,
           GroupElement& result_out);

private:
    const GeneratorVector& g_;
    const GeneratorVector& h_;
    const GroupElement& u_;
    const GroupElement& P_;

};

} // namespace bulletproofs

#endif //ZCASH_INNERPRODUCTPROOVER_H
