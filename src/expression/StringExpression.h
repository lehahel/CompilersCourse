#pragma once

#include <string>

#include <ForwardDeclarations.h>
#include "Expression.h"
#include <object/StringObject.hpp>

namespace Expr {

    const std::string STRING_EXPR_STR = "StringExpression: ";

    class CStringExpr : public CBase {
      public:
        CStringExpr(std::string value);
        void Accept(Visitor::CBase *visitor) override;
        // std::string GetValue() const;
        CObject *GetValue() const override;
        std::string ToString() const override;
      private:
        CStringObject *object_;
    };
} // namespace Expr
