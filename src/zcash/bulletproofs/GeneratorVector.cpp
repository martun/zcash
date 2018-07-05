#include "include/GeneratorVector.h"


namespace bulletproofs {

const GroupElement& GeneratorVector::get_g(int i) const {
    return generators_[i][0];
}

void GeneratorVector::get_vector_multiple(
        int range_start,
        int range_end,
        std::vector<Scalar>::const_iterator& power_start,
        std::vector<Scalar>::const_iterator& power_end,
        GroupElement& result_out) const {

    while(power_start != power_end || range_start != range_end)
    {
       GroupElement temp;
       temp =  get_g(range_start) * *power_start;
       result_out += temp;
       ++power_start;
       ++range_start;
    }
}

int GeneratorVector::size() const {
    return generators_.size();
}

} // namespace bulletproofs