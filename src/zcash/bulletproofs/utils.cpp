#include "include/utils.h"
#include <../../secp256k1/src/hash.h>
#include <string.h>

namespace bulletproofs {

Scalar scalar_dot_product(
        std::vector<Scalar>::const_iterator a_start,
        std::vector<Scalar>::const_iterator a_end,
        std::vector<Scalar>::const_iterator b_start,
        std::vector<Scalar>::const_iterator b_end) {
    Scalar result(0);
    auto itr_a = a_start;
    auto itr_b = b_start;
    while(itr_a != a_end || itr_b != b_end) {
        result += *itr_a * *itr_b;
        ++itr_a;
        ++itr_b;
    }
    return result;
}

Scalar get_x(const GroupElement& L, const GroupElement& R) {
    secp256k1_sha256 hash;
    secp256k1_sha256_initialize(&hash);
    unsigned char data[4 * sizeof(secp256k1_fe)];
    memcpy(data, L.serialize(), 2 * sizeof(secp256k1_fe));
    memcpy(data + 2 * sizeof(secp256k1_fe), R.serialize(), 2 * sizeof(secp256k1_fe));
    secp256k1_sha256_write(&hash, data, 2 * sizeof(secp256k1_fe));
    unsigned char result_data[32];
    secp256k1_sha256_finalize(&hash, result_data);
    secp256k1_scalar result;
    memcpy(&result, result_data, 32);
    return Scalar(result);
}

Scalar get_x(const GroupElement& P) {
    secp256k1_sha256 hash;
    secp256k1_sha256_initialize(&hash);
    unsigned char data[2 * sizeof(secp256k1_fe)];
    memcpy(data, P.serialize(), 2 * sizeof(secp256k1_fe));
    secp256k1_sha256_write(&hash, data, 32);
    unsigned char result_data[32];
    secp256k1_sha256_finalize(&hash, result_data);
    secp256k1_scalar result;
    memcpy(&result, result_data, 32);
    return Scalar(result);
}

} // namespace bulletproofs