#pragma once

#include "expression.h"

class CAddExpression : public CExpression {
  public:
    CAddExpression(
        CExpression *left, CExpression *right);
    int eval() const override;
  private:
    CExpression *left_;
    CExpression *right_;
};