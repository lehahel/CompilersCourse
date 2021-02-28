#pragma once

#include "expression.h"

class CBiggerExpression : public CExpression {
  public:
    CBiggerExpression(
        CExpression *left, CExpression *right);
    int eval() const override;

  private:
    CExpression *left_;
    CExpression *right_;
};