#pragma once

#include <ForwardDeclarations.h>
#include "Expression.h"
#include <object/IntObject.hpp>

namespace Expr {
    class CIntExpr : public CBase {
      public:
        CIntExpr(int value);
        void Accept(Visitor::CBase *visitor);
        int GetValue() const;
        std::string GetExprName() const override;
      private:
        CIntObject *object_;
    };
} // namespace Expr
