#include "IntExpression.h"

Expr::CIntExpr::CIntExpr(int value) : object_(new CIntObject(value)) {};

void Expr::CIntExpr::Accept(Visitor::CBase *visitor) {
    visitor->Visit(this);
}

CObject *Expr::CIntExpr::GetValue() const {
    return object_;
}

std::string Expr::CIntExpr::ToString() const {
    return INT_EXPR_STR + object_->ToString();
}
