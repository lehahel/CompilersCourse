#include "NumberExpression.h"

Expr::CNumber::CNumber(
    int value
) : value_(value) {}

void Expr::CNumber::Accept(
    Visitor::CBase *visitor
) {
   visitor->Visit(this);
}