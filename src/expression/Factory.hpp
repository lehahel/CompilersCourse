#pragma once

#include "Expression.h"

#include "IdentExpression.h"

#include "BinaryOpExpression.h"
#include "UnaryOpExpression.h"

#include "BoolExpression.h"
#include "StringExpression.h"
#include "IntExpression.h"
#include "DoubleExpression.h"

namespace Expr {

CBase *CreateInt(int value) {
    return new CIntExpr(value);
}

CBase *CreateDouble(double value) {
    return new CDoubleExpr(value);
}

CBase *CreateBool(bool value) {
    return new CBoolExpr(value);
}

CBase *CreateString(const std::string &value) {
    return new CStringExpr(value);
}

CBase *CreateIdent(const std::string &name) {
    return new CIdent(name);
}

CBase *CreateAdd(CBase *left, CBase *right) {
    return new CBinaryOperation(ADD, left, right);
}

CBase *CreateSub(CBase *left, CBase *right) {
    return new CBinaryOperation(SUB, left, right);
}

CBase *CreateMul(CBase *left, CBase *right) {
    return new CBinaryOperation(MUL, left, right);
}

CBase *CreateDiv(CBase *left, CBase *right) {
    return new CBinaryOperation(DIV, left, right);
}

CBase *CreateBigger(CBase *left, CBase *right) {
    return new CBinaryOperation(BIGGER, left, right);
}

CBase *CreateLess(CBase *left, CBase *right) {
    return new CBinaryOperation(LESS, left, right);
}

CBase *CreateLequal(CBase *left, CBase *right) {
    return new CBinaryOperation(LEQUAL, left, right);
}

CBase *CreateBequal(CBase *left, CBase *right) {
    return new CBinaryOperation(BEQUAL, left, right);
}

CBase *CreateEqual(CBase *left, CBase *right) {
    return new CBinaryOperation(EQUAL, left, right);
}

CBase *CreateNequal(CBase *left, CBase *right) {
    return new CBinaryOperation(NEQUAL, left, right);
}

CBase* CreateMinus(Expr::CBase *expr) {
    return new Expr::CUnaryOperation(Expr::MINUS, expr);
}

CBase *CreateNot(Expr::CBase *expr) {
    return new Expr::CUnaryOperation(Expr::NOT, expr);
}

};