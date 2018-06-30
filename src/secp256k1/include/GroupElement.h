#ifndef SECP_GROUP_ELEMENT_H__
#define SECP_GROUP_ELEMENT_H__

#include "Scalar.h"

class secp256k1_scalar;
class secp256k1_ge;

namespace bulletproofs {

class GroupElement {
public:
  GroupElement(const secp256k1_gej& g);
	
	// Operator for multiplying with a scalar number.
	GroupElement operator*(const Scalar& multiplier) const;

	// Operator for multiplying with a scalar number.
	GroupElement& operator*=(const Scalar& multiplier);

	// Operator for adding to another element.
	GroupElement operator+(const GroupElement& other) const;

	// Operator for adding to another element.
	GroupElement& operator+=(const GroupElement& other);

private:

	// Converts the value from secp256k1_gej to secp256k1_ge and returns.
	secp256k1_ge to_ge() const;

private:
  secp256k1_gej g_;

};

} // namespace bulletproofs

#endif // SECP_GROUP_ELEMENT_H__
