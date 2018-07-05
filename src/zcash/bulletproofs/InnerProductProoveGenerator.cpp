#include "include/InnerProductProoveGenerator.h"

namespace bulletproofs {

InnerProductProoveGenerator::InnerProductProoveGenerator(
        const GeneratorVector& g,
        const GeneratorVector& h,
        const GroupElement& u,
        const GroupElement& P)
    : g_(g)
    , h_(h)
    , u_(u)
    , P_(P)
{

}

void InnerProductProoveGenerator::generate_proof(
            const std::vector<Scalar> &a,
            const std::vector<Scalar> &b,
            InnerProductProof& proof_out) {
// TODO
}


void InnerProductProoveGenerator::hash(
        std::vector<Scalar>::const_iterator& a1_start,
        std::vector<Scalar>::const_iterator& a1_end,
        std::vector<Scalar>::const_iterator& a2_start,
        std::vector<Scalar>::const_iterator& a2_end,
        std::vector<Scalar>::const_iterator& b1_start,
        std::vector<Scalar>::const_iterator& b1_end,
        std::vector<Scalar>::const_iterator& b2_start,
        std::vector<Scalar>::const_iterator& b2_end,
        const Scalar& c,
        GroupElement& result_out) {
    GroupElement g1, g2, h1, h2, uc;

    g_.get_vector_multiple(g_.size() / 2 + 1, g_.size(), a1_start, a1_end, g1);
    g_.get_vector_multiple(0, g_.size()/2 + 1, a2_start, a2_end, g2);

    h_.get_vector_multiple(h_.size() / 2 + 1, h_.size(), b1_start, b1_end, h1);
    h_.get_vector_multiple(0, h_.size() / 2 + 1, b2_start, b2_end, h2);

    uc = u_ * c;

    result_out = g1 + g2 + h1 + h2 + uc;
}


void InnerProductProoveGenerator::l(
        std::vector<Scalar>::const_iterator& a_start,
        std::vector<Scalar>::const_iterator& a_end,
        std::vector<Scalar>::const_iterator& b_start,
        std::vector<Scalar>::const_iterator& b_end,
        const Scalar& cL,
        GroupElement& result_out) {
    GroupElement g, h, ucL;

    g_.get_vector_multiple(0, g_.size() / 2 + 1, a_start, a_end, g);
    h_.get_vector_multiple(h_.size() / 2 + 1 , h_.size(), b_start, b_end, h);
    ucL = u_ * cL;

    result_out = g + h + ucL;
}

void InnerProductProoveGenerator::r(
       std::vector<Scalar>::const_iterator& a_start,
       std::vector<Scalar>::const_iterator& a_end,
       std::vector<Scalar>::const_iterator& b_start,
       std::vector<Scalar>::const_iterator& b_end,
       const Scalar& cR,
       GroupElement& result_out) {
    GroupElement g, h, ucR;

    g_.get_vector_multiple(g_.size() / 2 + 1, g_.size(), a_start, a_end, g);
    h_.get_vector_multiple(0, h_.size() / 2 + 1, b_start, b_end, h);
    ucR = u_ * cR;
    result_out = g + h + ucR;
}

} // namespace bulletproofs
