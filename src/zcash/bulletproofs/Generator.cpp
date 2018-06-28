#include "include/Generator.h"

#include <secp256k1/src/ecmult_const.h>
#include <secp256k1/src/ecmult.h>


namespace bulletproofs {

Generator(const secp256k1_ge& g, int precomp = 32) {
    // TODO(martun): precompute the values in multiples_of_g_
		multiples_of_g_.reserve(precomp);
		multiples_of_g_.emplace_back(g);
}

void Generator::get_multiple(const secp256k1_scalar& power, secp256k1_gej& result_out) const {
	secp256k1_ecmult_const(&result_out, &multiples_of_g_[0], &power);
}

void Generator::get_multiple(const secp256k1_scalar& power, secp256k1_ge& result_out) const {
	secp256k1_gej result_jacobian;
	secp256k1_ecmult_const(&result_jacobian, &this->multiples_of_g_[0], &power);
	secp256k1_ge_set_gej(&result_out, &result_jacobian);

}

} // namespace bulletproofs