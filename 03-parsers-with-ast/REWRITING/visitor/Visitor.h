#pragma once

#include "expression/expression.h"

namespace Visitor {
    class Base {
      public:
        virtual void Visit(CExpression *expr) = 0;
    };
};