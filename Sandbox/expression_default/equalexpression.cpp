#include "equalexpression.h"

CEqualExpression::CEqualExpression(
    CExpression *left, CExpression *right) :
        left_(left), right_(right) {};

int CEqualExpression::eval() const {
    return left_->eval() == right_->eval() ? 1 : 0;
}