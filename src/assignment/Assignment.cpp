#include "Assignment.h"

CAssignment::CAssignment(Lvalue::CIdentifier *identifier, 
    Expr::CBase *expr) : identifier_(identifier), expr_(expr) {};

void CAssignment::Accept(Visitor::CBase *visitor) {
    visitor->Visit(this);
}

std::string CAssignment::ToString() const {
    return "Assignment";
}
