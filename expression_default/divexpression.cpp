#include "divexpression.h"

CDivExpression::CDivExpression(
    CExpression *left, CExpression *right) :
        left_(left), right_(right) {};

int CDivExpression::eval() const {
    return left_->eval() / right_->eval();
}