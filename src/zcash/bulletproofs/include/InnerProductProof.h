#ifndef ZCASH_INNERPRODUCTPROOF_H
#define ZCASH_INNERPRODUCTPROOF_H

namespace bulletproofs {

// Storage of the proof.
class InnerProductProof {
public:
    void set_a(const Scalar& a);

    void set_b(const Scalar& b);

    void set_c(const Scalar& c);

    Scalar& get_c();

    Scalar& get_a();

    Scalar& get_b();

    void push_l(GroupElement& l);

    void push_r(GroupElement& r);

    std::vector<GroupElement>::const_iterator l_begin();

    std::vector<GroupElement>::const_iterator l_end();

    std::vector<GroupElement>::const_iterator r_end();

    std::vector<GroupElement>::const_iterator r_begin();

private:
    Scalar a_;
    Scalar b_;
    Scalar c_;
    std::vector<GroupElement> L_;
    std::vector<GroupElement> R_;
};

} // namespace bulletproofs
#endif //ZCASH_INNERPRODUCTPROOF_H
