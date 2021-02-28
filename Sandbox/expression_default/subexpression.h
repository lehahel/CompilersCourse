#pragma once

#include "expression.h"

class CSubExpression : public CExpression {
  public:
    CSubExpression(
        CExpression *left, CExpression *right);
    int eval() const override;
  private:
    CExpression *left_;
    CExpression *right_;
};