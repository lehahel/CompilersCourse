#pragma once

#include <ForwardDeclarations.h>
#include "Expression.h"
#include <object/BoolObject.hpp>

namespace Expr {
    class CBoolExpr : public CBase {
      public:
        CBoolExpr(bool value);
        void Accept(Visitor::CBase *visitor);
        bool GetValue() const;
        std::string GetExprName() const override;
      private:
        CBoolObject *object_;
    };
} // namespace Expr
