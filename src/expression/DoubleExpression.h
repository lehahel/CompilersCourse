#pragma once

#include <ForwardDeclarations.h>
#include "Expression.h"
#include <object/DoubleObject.hpp>

namespace Expr {
    class CDoubleExpr : public CBase {
      public:
        CDoubleExpr(double value);
        void Accept(Visitor::CBase *visitor);
        double GetValue() const;
        std::string GetExprName() const override;
      private:
        CDoubleObject *object_;
    };
} // namespace Expr
