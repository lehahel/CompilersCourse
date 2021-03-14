#include "IntExpression.h"

Expr::CIntExpr::CIntExpr(int value) : object_(new CIntObject(value)) {};

void Expr::CIntExpr::Accept(Visitor::CBase *visitor) {
    visitor->Visit(this);
}

int Expr::CIntExpr::GetValue() const {
    return object_->value;
}
