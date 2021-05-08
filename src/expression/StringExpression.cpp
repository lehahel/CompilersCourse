#include "StringExpression.h"

Expr::CStringExpr::CStringExpr(std::string value) : object_(new CStringObject(value)) {};

void Expr::CStringExpr::Accept(Visitor::CBase *visitor) {
    visitor->Visit(this);
}

CObject *Expr::CStringExpr::GetValue() const {
    return object_;
}

std::string Expr::CStringExpr::ToString() const {
    return STRING_EXPR_STR + object_->ToString();
}
