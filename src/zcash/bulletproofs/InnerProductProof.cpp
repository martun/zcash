#include "include/InnerProductProof.h"

namespace bulletproofs {

void InnerProductProof::set_a(const Scalar a) {
    a_ = a;
}
void InnerProductProof::set_b(const Scalar b){
    b_ = b;
}

void InnerProductProof::set_b(const Scalar c){
    c_ = c;
}

Scalar& InnerProductProof::get_a(){
    return a_;
}

Scalar& InnerProductProof::get_b(){
    return b_;
}

Scalar& InnerProductProof::get_c(){
    return c_;
}


void InnerProductProof::push_l(GroupElement& l){
    L.push_back(l);
}
void InnerProductProof::push_r(GroupElement& r){
    R.push_back(r);
}

std::vector<GroupElement>::const_iterator InnerProductProof::l_begin(){
    return L_.begin();
}

std::vector<GroupElement>::const_iterator InnerProductProof::l_end(){
    return L_.end();
}

std::vector<GroupElement>::const_iterator InnerProductProof::r_end(){
    return R_.end();
}

std::vector<GroupElement>::const_iterator InnerProductProof::r_begin(){
    return R_.begin();
}


} // namespace bulletproofs