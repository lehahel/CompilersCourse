#include "addexpression.h"

CAddExpression::CAddExpression(
    CExpression *left, CExpression *right) :
        left_(left), right_(right) {};

int CAddExpression::eval() const {
    return left_->eval() + right_->eval();
}