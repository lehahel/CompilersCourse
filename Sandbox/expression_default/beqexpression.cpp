#include "beqexpression.h"

CBeqExpression::CBeqExpression(
    CExpression *left, CExpression *right) :
        left_(left), right_(right) {};

int CBeqExpression::eval() const {
    return left_->eval() >= right_->eval() ? 1 : 0;
}