#include "BinaryOpExpression.h"

Expression::CBinaryOperation::CBinaryOperation(
    BinaryOperatorType type,
    Expression::CBase *left,
    Expression::CBase *right
) : type_(type), left_(left), right_(right) {}

static Expression::CBinaryOperation::CBinaryOperation*
CreateAdd(Expression::CBase *left, Expression::CBase *right) {
    return new Expression::CBinaryOperation(Expression::ADD, left, right);
}

static Expression::CBinaryOperation::CBinaryOperation*
CreateSub(Expression::CBase *left, Expression::CBase *right) {
    return new Expression::CBinaryOperation(Expression::SUB, left, right);
}

static Expression::CBinaryOperation::CBinaryOperation*
CreateMul(Expression::CBase *left, Expression::CBase *right) {
    return new Expression::CBinaryOperation(Expression::MUL, left, right);
}

static Expression::CBinaryOperation::CBinaryOperation*
CreateDiv(Expression::CBase *left, Expression::CBase *right) {
    return new Expression::CBinaryOperation(Expression::DIV, left, right);
}

static Expression::CBinaryOperation::CBinaryOperation*
CreateBigger(Expression::CBase *left, Expression::CBase *right) {
    return new Expression::CBinaryOperation(Expression::BIGGER, left, right);
}

static Expression::CBinaryOperation::CBinaryOperation*
CreateLess(Expression::CBase *left, Expression::CBase *right) {
    return new Expression::CBinaryOperation(Expression::LESS, left, right);
}

static Expression::CBinaryOperation::CBinaryOperation*
CreateLequal(Expression::CBase *left, Expression::CBase *right) {
    return new Expression::CBinaryOperation(Expression::LEQUAL, left, right);
}

static Expression::CBinaryOperation::CBinaryOperation*
CreateBequal(Expression::CBase *left, Expression::CBase *right) {
    return new Expression::CBinaryOperation(Expression::BEQUAL, left, right);
}

static Expression::CBinaryOperation::CBinaryOperation*
CreateEqual(Expression::CBase *left, Expression::CBase *right) {
    return new Expression::CBinaryOperation(Expression::EQUAL, left, right);
}

static Expression::CBinaryOperation::CBinaryOperation*
CreateNequal(Expression::CBase *left, Expression::CBase *right) {
    return new Expression::CBinaryOperation(Expression::NEQUAL, left, right);
}
