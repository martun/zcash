#ifndef ZCASH_GENERATORVECTOR_H
#define ZCASH_GENERATORVECTOR_H

class GerneratorVector {
public:
    Gernerator(const std::vector<secp256k1_ge>& generators, int precomp = 32);

    /**
     * \param[in] power The power of g which we want to compute.
     * \param[out] result_out The result of computation.
     * \returns g^power in output parameter result_out.
     */
    void get_vector_power(
            const std::vector<secp256k1_scalar>::const_iterator& power_start,
            const std::vector<secp256k1_scalar>::const_iterator& power_end,
            secp256k1_ge& result_out) const;

private:
    // powers_of_g_[i] = g^(2^i).
    std::vector<Generator> generators_;
};

#endif //ZCASH_GENERATORVECTOR_H
