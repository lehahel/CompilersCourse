#pragma once

#include "expression.h"

class CMulExpression : public CExpression {
  public:
    CMulExpression(
        CExpression *left, CExpression *right);
    int eval() const override;
  private:
    CExpression *left_;
    CExpression *right_;
};