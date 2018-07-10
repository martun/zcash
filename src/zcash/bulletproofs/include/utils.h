#ifndef ZCASH_UTILS_H
#define ZCASH_UTILS_H

#include <secp256k1/include/Scalar.h>
#include <vector>
#include <secp256k1/include/Scalar.h>
#include <secp256k1/include/GroupElement.h>
namespace bulletproofs {

// computes dot product of two scalar vectors
    Scalar scalar_dot_product(
            std::vector<Scalar>::const_iterator a_start,
            std::vector<Scalar>::const_iterator a_end,
            std::vector<Scalar>::const_iterator b_start,
            std::vector<Scalar>::const_iterator b_end);


    Scalar get_x(const GroupElement& L, const GroupElement& R);

    Scalar get_x(const GroupElement& P);

} // namespace bulletproofs

#endif //ZCASH_UTILS_H
