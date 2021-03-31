#include "BinaryOpExpression.h"

Expr::CBinaryOperation::CBinaryOperation(
    BinaryOperatorType type,
    Expr::CBase *left,
    Expr::CBase *right
) : type_(type), left_(left), right_(right) {}

void Expr::CBinaryOperation::Accept(Visitor::CBase *visitor) {
    visitor->Visit(this);
}

std::string Expr::CBinaryOperation::GetExprName() const {
    if (type_ == Expr::ADD) {
        return "AddExpression";
    }
    if (type_ == Expr::SUB) {
        return "SubExpression";
    }
    if (type_ == Expr::MUL) {
        return "MulExpression";
    }
    if (type_ == Expr::DIV) {
        return "DivExpression";
    }
    if (type_ == Expr::BIGGER) {
        return "BiggerExpression";
    }
    if (type_ == Expr::LESS) {
        return "LessExpression";
    }
    if (type_ == Expr::BEQUAL) {
        return "BequalExpression";
    }
    if (type_ == Expr::LEQUAL) {
        return "LequalExpression";
    }
    if (type_ == Expr::EQUAL) {
        return "EqualExpression";
    }
    if (type_ == Expr::NEQUAL) {
        return "NequalExpression";
    }
    return "ERROR";
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
