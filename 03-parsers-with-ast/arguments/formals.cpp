#include "formals.h"

void CFormals::append(Formal formal) {
    formals_.emplace_back(formal);
}

Formal CFormals::operator[](size_t idx) const {
    return formals_[idx];
}

size_t CFormals::get_size() const {
    return formals_.size();
}