#pragma once

#include <expression/Expression.h>

namespace Visitor {
    class CBase {
      public:
        virtual void Visit(Expr::CBase *expr) = 0;
    };
};