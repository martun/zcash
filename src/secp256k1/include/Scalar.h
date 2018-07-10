#ifndef SCALAR_H__
#define SCALAR_H__

#include <stdint.h>
#include <memory>
#include "secp256k1.h"
#include "../src/util.h"
#include "../src/scalar.h"

namespace bulletproofs {
// A wrapper over scalar value of Secp library.
    class Scalar {
    public:

        Scalar();
        // Constructor from interger.
        Scalar(uint64_t value);

        // Constructor from secp object.
        Scalar(const secp256k1_scalar &value);

        // Copy constructor
        Scalar(const Scalar& other);

        // Move constructor
        Scalar(Scalar&& other);

        Scalar& operator=(const Scalar& other);

        Scalar& operator=(Scalar&& other) noexcept;

        Scalar& operator=(unsigned int i);

        Scalar operator*(const Scalar& other) const;

        Scalar& operator*=(const Scalar& other);

        Scalar operator+(const Scalar& other) const;

        Scalar& operator+=(const Scalar& other);

        Scalar inverse() const;

        Scalar square() const;

        // Returns the secp object inside it.
        const secp256k1_scalar &get_value() const;


    private:
        std::unique_ptr <secp256k1_scalar> value_;

    };

}
#endif // SCALAR_H__
