#pragma once

#include "Expression.h"
#include <object/IntObject.hpp>
#include <ForwardDeclarations.h>

namespace Expr {
    class CIntExpr : public CBase {
      public:
        CIntExpr(int value);
        void Accept(Visitor::CBase *visitor) override;
        int GetValue() const;
        std::string GetExprName() const override;
      private:
        CIntObject *object_;
    };
} // namespace Expr
