#ifndef BULLETPROOFS_PRECOMPUTED_GROUP_ELEMENT_H
#define BULLETPROOFS_PRECOMPUTED_GROUP_ELEMENT_H

#include "secp256k1/src/cpp/Scalar.h"
#include "secp256k1/src/cpp/GroupElement.h"

namespace bulletproofs {

class PrecomputedGroupElement {
public:
	// Precomputes some multiples of g and stores in multiples_of_g_.
	PrecomputedGroupElement(const GroupElement& g, uint8_t precomp = 32);

	// Operator for multiplying with a scalar number.
	GroupElement operator*(const Scalar& multiplier) const;

	// Operator for multiplying with a scalar number.
	GroupElement& operator*=(const Scalar& multiplier);

	// Operator for adding to another element.
	GroupElement operator+(const GroupElement& other) const;

	// Operator for adding to another element.
	GroupElement& operator+=(const GroupElement& other);

private:
	// multiples_of_g_[i] = g * (2^i) in Eliptic Curve field.
	std::vector<GroupElement> multiples_of_g_;

};

} // namespace bulletproofs

#endif // BULLETPROOFS_PRECOMPUTED_GROUP_ELEMENT_H
