#pragma once

#include "expression.h"

class CNeqExpression : public CExpression {
  public:
    CNeqExpression(
        CExpression *left, CExpression *right);
    int eval() const override;

  private:
    CExpression *left_;
    CExpression *right_;
};