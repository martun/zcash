#include "GerneratorVector.h"


namespace bulletproofs {

const Generator& GerneratorVector::get_g(int i){
    return generators[i];
}

void GerneratorVector::get_vector_multiply(
        int range_start,
        int range_end,
        const std::vector<secp256k1_scalar>::const_iterator& power_start,
        const std::vector<secp256k1_scalar>::const_iterator& power_end,
        secp256k1_ge& result_out) const
{
    secp256k1_gej result_jacobian;

    while(power_start != power_end || range_start != range_end)
    {
        secp256k1_ge ge;
        generators_[range_start].get_multiple(*power_start,&ge);

        secp256k1_gej_add_ge(&result_jacobian, &result_jacobian, &ge);

        ++power_start; ++range_start;
    }

    secp256k1_ge_set_gej(&result_out, &result_jacobian);
}

} // namespace bulletproofs