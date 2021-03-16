#include "DoubleExpression.h"

Expr::CDoubleExpr::CDoubleExpr(double value) : object_(new CDoubleObject(value)) {};

void Expr::CDoubleExpr::Accept(Visitor::CBase *visitor) {
    visitor->Visit(this);
}

double Expr::CDoubleExpr::GetValue() const {
    return object_->value;
}

std::string Expr::CDoubleExpr::GetExprName() const {
    return "DoubleExpression";
}
