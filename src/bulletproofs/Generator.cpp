#include "GerneratorPrecomputedStorage.h"

#include <ecmult_const.h>
#include <ecmult.h>

Gernerator(const secp256k1_ge& g, int precomp = 32) {
    // TODO(martun): precompute the values in multiples_of_g_
		multiples_of_g_.reserve(precomp);
		multiples_of_g_.emplace_back(g);
}

void Gernerator::get_multiple(const secp256k1_scalar& power, secp256k1_ge& result_out) const {
	secp256k1_gej result_jacobian;
	secp256k1_ecmult_const(&result_jacobian, &multiples_of_g_[0], &power);
}

