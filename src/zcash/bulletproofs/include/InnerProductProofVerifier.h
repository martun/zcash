
#ifndef ZCASH_INNERPRODUCTPROOFVERIFIER_H
#define ZCASH_INNERPRODUCTPROOFVERIFIER_H


namespace bulletproofs {

class InnerProductProofVerifier {

public:
    InnerProductProofVerifier(
        const GeneratorVector& g,
        const GeneratorVector& h,
        const GroupElement& u,
        const GroupElement& P);

    bool verify (const InnerProductProof& proof);

    GeneratorVector g_prime(const Scalar& x);

    GeneratorVector h_prime(const Scalar& x);

    GroupElement p_prime(const GroupElement& L,const GroupElement& R, const Scalar& x);

private:
    bool verify_util(const InnerProductProof& proof, std::vector<GroupElement>::const_iterator ltr_l, std::vector<GroupElement>::const_iterator itr_r);

private:
    const GeneratorVector& g_;
    const GeneratorVector& h_;
    const GroupElement& u_;
    const GroupElement& P_;
};

} // namespace bulletproofs
#endif //ZCASH_INNERPRODUCTPROOFVERIFIER_H
