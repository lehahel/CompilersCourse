#include "subexpression.h"

CSubExpression::CSubExpression(
    CExpression *left, CExpression *right) :
        left_(left), right_(right) {};

int CSubExpression::eval() const {
    return left_->eval() - right_->eval();
}