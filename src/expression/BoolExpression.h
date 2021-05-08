#pragma once

#include <ForwardDeclarations.h>
#include "Expression.h"
#include <object/BoolObject.hpp>

namespace Expr {

    const std::string BOOL_EXPR_STR = "BoolExpression: ";

    class CBoolExpr : public CBase {
      public:
        CBoolExpr(bool value);
        void Accept(Visitor::CBase *visitor) override;
        CObject *GetValue() const override;
        std::string ToString() const override;
      private:
        CBoolObject *object_;
    };
} // namespace Expr
