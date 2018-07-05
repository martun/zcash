#include "include/utils.h"


namespace bulletproofs {

Scalar scalar_dot_product(
        const std::vector<Scalar> &a,
        const std::vector<Scalar> &b) {
    Scalar result(0);
    for(int i = 0; i <= a.size(); ++i) {
        result += a[i] * b[i];
    }
    return result;
}

} // namespace bulletproofs