#pragma once

#include "expression_default/expression.h"

#include <string>

class CAssignment {
  public:
    CAssignment(
        const std::string &variable,
        CExpression *expression
    );
  
  private:
    std::string variable_;
    CExpression *expression_;
};