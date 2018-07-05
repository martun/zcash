#ifndef ZCASH_GENERATORVECTOR_H
#define ZCASH_GENERATORVECTOR_H

#include <iostream>
#include <vector>
#include <secp256k1/include/Scalar.h>
#include <secp256k1/include/GroupElement.h>

namespace bulletproofs {
class GeneratorVector {
public:
    GeneratorVector(const std::vector<GroupElement>& generators, int precomp = 32);

    /**
     * \param[in] power The power of g which we want to compute.
     * \param[out] result_out The result of computation.
     * \returns g^power in output parameter result_out.
     */
    void get_vector_multiple(
            int range_start,
            int range_end,
            std::vector<Scalar>::const_iterator& power_start,
            std::vector<Scalar>::const_iterator& power_end,
            GroupElement& result_out) const;

    const GroupElement& get_g(int i) const;

    int size() const;

private:
    // powers_of_g_[i] = g^(2^i).
    std::vector<std::vector<GroupElement>> generators_;
};

} // namespace bulletproofs
#endif //ZCASH_GENERATORVECTOR_H
