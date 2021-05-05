#include "BoolExpression.h"

Expr::CBoolExpr::CBoolExpr(bool value) : object_(new CBoolObject(value)) {};

void Expr::CBoolExpr::Accept(Visitor::CBase *visitor) {
    visitor->Visit(this);
}

CObject *Expr::CBoolExpr::GetValue() const {
    return object_;
}

std::string Expr::CBoolExpr::ToString() const {
    return BOOL_EXPR_STR + object_->ToString();
}