#include "GroupElement.h"

#include "group.h"

GroupElement::GroupElement(const secp256k1_ge& g) 
	: g_(g) 
{
}

secp256k1_ge GroupElement::to_ge() const {
	secp256k1_ge g_ge;
	secp256k1_ge_set_gej(&g_ge, &g_);
	return g_ge;
}

GroupElement GroupElement::operator*(const Scalar& multiplier) const {
	secp256k1_gej result;
	secp256k1_ecmult_const(&result, &g_.to_ge(), &multiplier.get_value());
	return GroupElement(result);
}

GroupElement& GroupElement::operator*=(const Scalar& multiplier) const {
	secp256k1_ecmult_const(&g_, &g_.to_ge(), &multiplier.get_value());
	return *this;
}

GroupElement GroupElement::operator+(const GroupElement& other) const {
	secp256k1_gej result_gej;

	secp256k1_gej_add_var(&result_gej, &g_, other.g_, NULL);
	return GroupElement(result_gej);
}

GroupElement GroupElement::operator+=(const GroupElement& other) const {
	secp256k1_gej_add_var(&this.g_, &this.g_, other.g_, NULL);
}

