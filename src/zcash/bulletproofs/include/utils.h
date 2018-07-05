#ifndef ZCASH_UTILS_H
#define ZCASH_UTILS_H

#include <secp256k1/include/Scalar.h>
#include <vector>

namespace bulletproofs {

// computes dot product of two scalar vectors
    Scalar scalar_dot_product(const std::vector<Scalar> &a,
            const std::vector<Scalar> &b);

} // namespace bulletproofs

#endif //ZCASH_UTILS_H
