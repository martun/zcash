#include "Scalar.h"
#include "scalar.h"
#include "../hash_impl.h"


namespace bulletproofs {

 Scalar::Scalar()
		 : value_(new secp256k1_scalar()) {
 }

 Scalar::Scalar(uint64_t value)
		 : value_(new secp256k1_scalar()) {
	 secp256k1_scalar_set_int(value_.get(), value);
 }

 Scalar::Scalar(const secp256k1_scalar &value)
		 : value_(new secp256k1_scalar(value)) {

 }

 Scalar::Scalar(const Scalar& other)
		 : value_(new secp256k1_scalar(*other.value_)) {

 }

 Scalar::Scalar(Scalar&& other)
		 : value_(new secp256k1_scalar(*other.value_)) {
	 other.value_ = nullptr;
 }

 Scalar& Scalar::operator=(const Scalar& other) {
	 *value_ = *other.value_;
	 return *this;
 }

 Scalar& Scalar::operator=(Scalar&& other) noexcept {
	 value_ = std::exchange(other.value_, nullptr);
	 return *this;
 }

 Scalar& Scalar::operator=(unsigned int i) {
	 secp256k1_scalar_set_int(value_.get(), i);
	 return *this;
 }

 Scalar Scalar::operator*(const Scalar& other) const {
	 secp256k1_scalar *result = new secp256k1_scalar();
	 secp256k1_scalar_mul(result, value_.get(), other.value_.get());
	 return Scalar(*result);
 }

 Scalar& Scalar::operator*=(const Scalar& other) {
	 secp256k1_scalar_mul(value_.get(), &(*value_), other.value_.get());
	 return *this;
 }

 Scalar Scalar::operator+(const Scalar& other) const {
	 secp256k1_scalar *result = new secp256k1_scalar();
	 secp256k1_scalar_add(result, value_.get(), other.value_.get());
	 return Scalar(*result);
 }

 Scalar& Scalar::operator+=(const Scalar& other) {
	 secp256k1_scalar_add(value_.get(), value_.get(), other.value_.get());
	 return *this;
 }

 const secp256k1_scalar &Scalar::get_value() const {
	 return *value_;
 }

 Scalar Scalar::inverse() const {
	 secp256k1_scalar *result = new secp256k1_scalar();
	 secp256k1_scalar_inverse(result, value_.get());
	 return Scalar(*result);
 }

 Scalar Scalar::square() const{
     secp256k1_scalar *result = new secp256k1_scalar();
     secp256k1_scalar_sqr(result, value_.get());
     return Scalar(*result);
 }

}

