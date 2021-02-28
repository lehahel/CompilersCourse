#include "biggerexpression.h"

CBiggerExpression::CBiggerExpression(
    CExpression *left, CExpression *right) :
        left_(left), right_(right) {};

int CBiggerExpression::eval() const {
    return left_->eval() > right_->eval() ? 1 : 0;
}