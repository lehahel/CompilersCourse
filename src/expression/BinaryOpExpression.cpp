#include "BinaryOpExpression.h"

Expr::CBinaryOperation::CBinaryOperation(
    BinaryOperatorType type,
    Expr::CBase *left,
    Expr::CBase *right
) : type_(type), left_(left), right_(right) {}

void Expr::CBinaryOperation::Accept(Visitor::CBase *visitor) {
    visitor->Visit(this);
}

CObject *Expr::CBinaryOperation::GetValue() const {
    return nullptr;
}

std::string Expr::CBinaryOperation::ToString() const {
    switch (type_) {

    case Expr::ADD:    return ADD_EXPR_STR;
    case Expr::SUB:    return SUB_EXPR_STR;
    case Expr::MUL:    return MUL_EXPR_STR;
    case Expr::DIV:    return DIV_EXPR_STR;
    case Expr::BIGGER: return BIGGER_EXPR_STR;
    case Expr::LESS:   return LESS_EXPR_STR;
    case Expr::BEQUAL: return BEQUAL_EXPR_STR;
    case Expr::LEQUAL: return LEQUAL_EXPR_STR;
    case Expr::EQUAL:  return EQUAL_EXPR_STR;
    case Expr::NEQUAL: return NEQUAL_EXPR_STR;
    
    default: std::abort();

    }
}

Expr::CBinaryOperation*
Expr::CBinaryOperation::CreateAdd(Expr::CBase *left, Expr::CBase *right) {
    return new Expr::CBinaryOperation(Expr::ADD, left, right);
}

Expr::CBinaryOperation*
Expr::CBinaryOperation::CreateSub(Expr::CBase *left, Expr::CBase *right) {
    return new Expr::CBinaryOperation(Expr::SUB, left, right);
}

Expr::CBinaryOperation*
Expr::CBinaryOperation::CreateMul(Expr::CBase *left, Expr::CBase *right) {
    return new Expr::CBinaryOperation(Expr::MUL, left, right);
}

Expr::CBinaryOperation*
Expr::CBinaryOperation::CreateDiv(Expr::CBase *left, Expr::CBase *right) {
    return new Expr::CBinaryOperation(Expr::DIV, left, right);
}

Expr::CBinaryOperation*
Expr::CBinaryOperation::CreateBigger(Expr::CBase *left, Expr::CBase *right) {
    return new Expr::CBinaryOperation(Expr::BIGGER, left, right);
}

Expr::CBinaryOperation*
Expr::CBinaryOperation::CreateLess(Expr::CBase *left, Expr::CBase *right) {
    return new Expr::CBinaryOperation(Expr::LESS, left, right);
}

Expr::CBinaryOperation*
Expr::CBinaryOperation::CreateLequal(Expr::CBase *left, Expr::CBase *right) {
    return new Expr::CBinaryOperation(Expr::LEQUAL, left, right);
}

Expr::CBinaryOperation*
Expr::CBinaryOperation::CreateBequal(Expr::CBase *left, Expr::CBase *right) {
    return new Expr::CBinaryOperation(Expr::BEQUAL, left, right);
}

Expr::CBinaryOperation*
Expr::CBinaryOperation::CreateEqual(Expr::CBase *left, Expr::CBase *right) {
    return new Expr::CBinaryOperation(Expr::EQUAL, left, right);
}

Expr::CBinaryOperation*
Expr::CBinaryOperation::CreateNequal(Expr::CBase *left, Expr::CBase *right) {
    return new Expr::CBinaryOperation(Expr::NEQUAL, left, right);
}
