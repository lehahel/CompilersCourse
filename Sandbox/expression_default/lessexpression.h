#pragma once

#include "expression.h"

class CLessExpression : public CExpression {
  public:
    CLessExpression(
        CExpression *left, CExpression *right);
    int eval() const override;

  private:
    CExpression *left_;
    CExpression *right_;
};