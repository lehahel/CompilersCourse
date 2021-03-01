#pragma once

#include "objects/object.h"
#include "expression.h"

class CAddExpression : public CExpression {
  public:
    CAddExpression(
        CExpression *left, CExpression *right);
    CObject eval() const override;
  private:
    CExpression *left_;
    CExpression *right_;
};