#include "IdentLvalue.h"

Lvalue::CIdentifier::CIdentifier(std::string identifier)
    : identifier_(identifier) {};

void Lvalue::CIdentifier::Accept(Visitor::CBase *visitor) {
    visitor->Visit(this);
}

std::string Lvalue::CIdentifier::ToString() const {
    return IDENT_STRING + identifier_;
}

std::string Lvalue::CIdentifier::GetIdentifier() const {
    return identifier_;
}
