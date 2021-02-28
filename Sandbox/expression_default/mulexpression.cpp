#include "mulexpression.h"

CMulExpression::CMulExpression(
    CExpression *left, CExpression *right) :
        left_(left), right_(right) {};

int CMulExpression::eval() const {
    return left_->eval() * right_->eval();
}