#pragma once

#include <expression/Expression.h>

namespace Visitor {
    class CBase {
      public:
        virtual void Visit(Expression::CBase *expr) = 0;
    };
};