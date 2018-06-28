#ifndef ZCASH_GERNERATOR_H
#define ZCASH_GERNERATOR_H

#include <secp256k1/src/scalar.h>
#include <secp256k1/src/group.h>

namespace bulletproofs {

class Generator {
public:
    Generator(const secp256k1_ge& g, int precomp = 32);

    /**
     * \param[in] power The power of g which we want to compute.
     * \param[out] result_out The result of computation.
     * \returns g^power in output parameter result_out.
     */
    void get_multiple(const secp256k1_scalar& power, secp256k1_ge& result_out) const;
    void get_multiple(const secp256k1_scalar& power, secp256k1_gej& result_out) const;

private:
    // multiples_of_g_[i] = g * (2^i) in Eliptic Curve field.
    std::vector<secp256k1_ge> multiples_of_g_;
};

} // namespace bulletproofs

#endif //ZCASH_GERNERATORPRECOMPUTEDSTORAGE_H
