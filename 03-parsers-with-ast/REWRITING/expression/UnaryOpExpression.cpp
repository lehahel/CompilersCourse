#include "UnaryOpExpression.h"

Expression::CUnaryOperation::CUnaryOperation(
    UnaryOperatorType type,
    Expression::CBase *expr
) : type_(type), expr_(expr) {}

static Expression::CUnaryOperation::CUnaryOperation*
CreateAdd(Expression::CBase *expr) {
    return new Expression::CUnaryOperation(Expression::MINUS, expr);
}

static Expression::CUnaryOperation::CUnaryOperation*
CreateSub(Expression::CBase *expr) {
    return new Expression::CUnaryOperation(Expression::NOT, expr);
}
