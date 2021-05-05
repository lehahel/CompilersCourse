#pragma once

#include "Expression.h"
#include <object/IntObject.hpp>
#include <ForwardDeclarations.h>

namespace Expr {

    const std::string INT_EXPR_STR = "IntExpression: ";

    class CIntExpr : public CBase {
      public:
        CIntExpr(int value);
        void Accept(Visitor::CBase *visitor) override;
        // int GetValue() const;
        CObject *GetValue() const override;
        std::string ToString() const override;
      private:
        CIntObject *object_;
    };
} // namespace Expr
