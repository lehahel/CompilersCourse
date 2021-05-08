#pragma once

#include <ForwardDeclarations.h>
#include "Expression.h"
#include <object/DoubleObject.hpp>

#include <string>

namespace Expr {

    const std::string DOUBLE_EXPR_STR = "DoubleExpression: ";

    class CDoubleExpr : public CBase {
      public:
        CDoubleExpr(double value);
        void Accept(Visitor::CBase *visitor) override;
        // double GetValue() const;
        CObject *GetValue() const override;
        std::string ToString() const override;
      private:
        CDoubleObject *object_;
    };
} // namespace Expr
