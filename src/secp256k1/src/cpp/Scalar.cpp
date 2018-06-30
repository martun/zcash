#include "Scalar.h"

#include "scalar.h"

Scalar::Scalar(uint64_t value) {
	secp256k1_scalar_set_int(value_, value);
}

Scalar::Scalar(const secp256k1_scalar& value) 
	: value_(value) 
{

}

const secp256k1_scalar& Scalar::get_value() const {
	return value_;
}
