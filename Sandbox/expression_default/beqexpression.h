#pragma once

#include "expression.h"

class CBeqExpression : public CExpression {
  public:
    CBeqExpression(
        CExpression *left, CExpression *right);
    int eval() const override;

  private:
    CExpression *left_;
    CExpression *right_;
};