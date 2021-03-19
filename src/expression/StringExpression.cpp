#include "StringExpression.h"

Expr::CStringExpr::CStringExpr(std::string value) : object_(new CStringObject(value)) {};

void Expr::CStringExpr::Accept(Visitor::CBase *visitor) {
    visitor->Visit(this);
}

std::string Expr::CStringExpr::GetValue() const {
    return object_->value;
}

std::string Expr::CStringExpr::GetExprName() const {
    return "StringExpression";
}
