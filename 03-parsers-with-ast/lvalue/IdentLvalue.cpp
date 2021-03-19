#include "IdentLvalue.h"

Lvalue::CIdentifier::CIdentifier(std::string identifier)
    : identifier_(identifier) {};

void Lvalue::CIdentifier::Accept(Visitor::CBase *visitor) {
    visitor->Visit(this);
}

std::string Lvalue::CIdentifier::ToString() const {
    return "Identifier: " + identifier_;
}