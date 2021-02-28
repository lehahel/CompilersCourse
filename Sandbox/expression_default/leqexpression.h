#pragma once

#include "expression.h"

class CLeqExpression : public CExpression {
  public:
    CLeqExpression(
        CExpression *left, CExpression *right);
    int eval() const override;

  private:
    CExpression *left_;
    CExpression *right_;
};