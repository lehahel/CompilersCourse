#include "UnaryOpExpression.h"

Expr::CUnaryOperation::CUnaryOperation(
    UnaryOperatorType type,
    Expr::CBase *expr
) : type_(type), expr_(expr) {}

CObject *Expr::CUnaryOperation::GetValue() const {
    return nullptr;
}

void Expr::CUnaryOperation::Accept(Visitor::CBase *visitor) {
    visitor->Visit(this);
}

std::string Expr::CUnaryOperation::ToString() const {
    if (type_ == Expr::MINUS) {
        return MINUS_EXPR_STR;
    }
    if (type_ == Expr::NOT) {
        return NOT_EXPR_STR;
    }
    std::abort();
}

Expr::CUnaryOperation*
Expr::CUnaryOperation::CreateMinus(Expr::CBase *expr) {
    return new Expr::CUnaryOperation(Expr::MINUS, expr);
}

Expr::CUnaryOperation*
Expr::CUnaryOperation::CreateNot(Expr::CBase *expr) {
    return new Expr::CUnaryOperation(Expr::NOT, expr);
}
