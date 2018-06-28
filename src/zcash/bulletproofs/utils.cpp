#include "utils.h"


namespace bulletproofs {

void scalar_dot_product(const std::vector<secp256k1_scalar> &a,
        const std::vector<secp256k1_scalar> &b,
        secp256k1_scalar *r_out)
{
    int n = a.size();
    secp256k1_scalar_clear(r_out);
    for(int i = 0; i <= n ; ++i) {
        secp256k1_scalar term;
        secp256k1_scalar_mul(&term, &a[i], &b[i]);
        secp256k1_scalar_add(r_out, r_out, &term);
    }
}
} // namespace bulletproofs
