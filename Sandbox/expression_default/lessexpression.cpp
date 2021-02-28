#include "lessexpression.h"

CLessExpression::CLessExpression(
    CExpression *left, CExpression *right) :
        left_(left), right_(right) {};

int CLessExpression::eval() const {
    return left_->eval() < right_->eval() ? 1 : 0;
}