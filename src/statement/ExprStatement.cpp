#include "ExprStatement.h"

Statement::CExpr::CExpr(Expr::CBase *expr) : expr_(expr) {};

void Statement::CExpr::Accept(Visitor::CBase *visitor) {
    visitor->Visit(this);
}

std::string Statement::CExpr::ToString() const {
    return "ExprStatement";
}