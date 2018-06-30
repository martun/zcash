#ifndef ZCASH_UTILS_H
#define ZCASH_UTILS_H


namespace bulletproofs {

// computes dot product of two scalar vectors
void scalar_dot_product(const std::vector<secp256k1_scalar> &a,
        const std::vector<secp256k1_scalar> &b,
        secp256k1_scalar *r_out);
} // namespace bulletproofs
#endif //ZCASH_UTILS_H
