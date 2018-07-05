#include "include/GroupElement.h"

namespace bulletproofs {

    GroupElement::GroupElement()
            : g_(new secp256k1_gej())
    {
    }

    GroupElement::GroupElement(const GroupElement &other)
            : g_(new secp256k1_gej(*other.g_))
    {
    }

    GroupElement::GroupElement(const secp256k1_gej& g)
            : g_(new secp256k1_gej(g))
    {
    }


    GroupElement::~GroupElement()
    {
        delete g_.get();
    }


    secp256k1_ge GroupElement::to_ge() const
    {
        secp256k1_ge g_ge;
        secp256k1_ge_set_gej(&g_ge, g_.get());
        return g_ge;
    }

    GroupElement& GroupElement::operator=(const GroupElement &other)
    {
        *g_ = *other.g_;
        return *this;
    }

    GroupElement GroupElement::operator*(const Scalar& multiplier) const
    {
        secp256k1_gej result;
        secp256k1_ge temp = to_ge();
        secp256k1_ecmult_const(&result, &temp, &multiplier.get_value());

        return  GroupElement(result);
    }

    GroupElement& GroupElement::operator*=(const Scalar& multiplier)
    {
        secp256k1_ge temp = to_ge();
        secp256k1_ecmult_const(g_.get(), &temp, &multiplier.get_value());
        return *this;
    }

    GroupElement GroupElement::operator+(const GroupElement &other) const
    {
        secp256k1_gej result_gej;

        secp256k1_gej_add_var(&result_gej, g_.get(), &(*other.g_), NULL);
        return GroupElement(result_gej);
    }

    GroupElement& GroupElement::operator+=(const GroupElement& other)
    {
        secp256k1_gej_add_var(g_.get(), g_.get(), &(*other.g_), NULL);
        return *this;
    }

}

