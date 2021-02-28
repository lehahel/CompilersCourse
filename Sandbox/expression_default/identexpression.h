#pragma once

#include "expression.h"

#include <string>

class CIdentExpression : public CExpression {
  public:
    CIdentExpression(const std::string &ident);
    int eval() const override;
  private:
    std::string ident_;
};