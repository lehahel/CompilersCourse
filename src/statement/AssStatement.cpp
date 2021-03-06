#include "AssStatement.h"

#include <string>

Statement::CAssignment::CAssignment(Lvalue::CBase *lvalue, 
    Expr::CBase *expr) : lvalue_(lvalue), expr_(expr) {};

void Statement::CAssignment::Accept(Visitor::CBase *visitor) {
    visitor->Visit(this);
}

std::string Statement::CAssignment::ToString() const {
    return ASSIGNMENT_STR;
}
