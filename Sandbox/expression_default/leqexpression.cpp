#include "leqexpression.h"

CLeqExpression::CLeqExpression(
    CExpression *left, CExpression *right) :
        left_(left), right_(right) {};

int CLeqExpression::eval() const {
    return left_->eval() <= right_->eval() ? 1 : 0;
}