#include "UnaryOpExpression.h"

Expr::CUnaryOperation::CUnaryOperation(
    UnaryOperatorType type,
    Expr::CBase *expr
) : type_(type), expr_(expr) {}

void Expr::CUnaryOperation::Accept(Visitor::CBase *visitor) {
    visitor->Visit(this);
}

std::string Expr::CUnaryOperation::GetExprName() const {
    if (type_ == Expr::MINUS) {
        return "UnaryMinusExpression";
    }
    if (type_ == Expr::NOT) {
        return "NotExpression";
    }
}

static Expr::CUnaryOperation*
CreateAdd(Expr::CBase *expr) {
    return new Expr::CUnaryOperation(Expr::MINUS, expr);
}

static Expr::CUnaryOperation*
CreateSub(Expr::CBase *expr) {
    return new Expr::CUnaryOperation(Expr::NOT, expr);
}
