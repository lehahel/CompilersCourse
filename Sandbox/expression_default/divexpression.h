#pragma once

#include "expression.h"

class CDivExpression : public CExpression {
  public:
    CDivExpression(
        CExpression *left, CExpression *right);
    int eval() const override;
  private:
    CExpression *left_;
    CExpression *right_;
};