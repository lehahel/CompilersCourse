#pragma once

#include "expression.h"

class CEqualExpression : public CExpression {
  public:
    CEqualExpression(
        CExpression *left, CExpression *right);
    int eval() const override;

  private:
    CExpression *left_;
    CExpression *right_;
};