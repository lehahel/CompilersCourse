#include "neqexpression.h"

CNeqExpression::CNeqExpression(
    CExpression *left, CExpression *right) :
        left_(left), right_(right) {};

int CNeqExpression::eval() const {
    return left_->eval() != right_->eval() ? 1 : 0;
}