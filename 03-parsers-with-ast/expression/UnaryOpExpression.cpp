#include "UnaryOpExpression.h"

Expr::CUnaryOperation::CUnaryOperation(
    UnaryOperatorType type,
    Expr::CBase *expr
) : type_(type), expr_(expr) {}

static Expr::CUnaryOperation::CUnaryOperation*
CreateAdd(Expr::CBase *expr) {
    return new Expr::CUnaryOperation(Expr::MINUS, expr);
}

static Expr::CUnaryOperation::CUnaryOperation*
CreateSub(Expr::CBase *expr) {
    return new Expr::CUnaryOperation(Expr::NOT, expr);
}
