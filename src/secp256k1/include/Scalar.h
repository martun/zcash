#ifndef SCALAR_H__
#define SCALAR_H__

#include <stdint.h>

class secp256k1_scalar;

// A wrapper over scalar value of Secp library.
class Scalar {
public:

	// Constructor from interger.
	Scalar(uint64_t value);

  // Constructor from secp object.
	Scalar(const secp256k1_scalar& value);

	// Returns the secp object inside it.
	const secp256k1_scalar& get_value() const;

private:
	secp256k1_scalar value_;

};

#endif // SCALAR_H__
