#include "DoubleExpression.h"

Expr::CDoubleExpr::CDoubleExpr(double value) : object_(new CDoubleObject(value)) {};

void Expr::CDoubleExpr::Accept(Visitor::CBase *visitor) {
    visitor->Visit(this);
}

// double Expr::CDoubleExpr::GetValue() const {
//     return object_->value;
// }

CObject *Expr::CDoubleExpr::GetValue() const {
    return object_;
}

std::string Expr::CDoubleExpr::ToString() const {
    return DOUBLE_EXPR_STR + object_->ToString();
}
