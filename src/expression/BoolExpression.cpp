#include "BoolExpression.h"

Expr::CBoolExpr::CBoolExpr(bool value) : object_(new CBoolObject(value)) {};

void Expr::CBoolExpr::Accept(Visitor::CBase *visitor) {
    visitor->Visit(this);
}

bool Expr::CBoolExpr::GetValue() const {
    return object_->value;
}

std::string Expr::CBoolExpr::GetExprName() const {
    return "BoolExpression";
}