#pragma once

#include <string>

#include <ForwardDeclarations.h>
#include "Expression.h"
#include <object/StringObject.hpp>

namespace Expr {
    class CStringExpr : public CBase {
      public:
        CStringExpr(std::string value);
        void Accept(Visitor::CBase *visitor);
        std::string GetValue() const;
        std::string GetExprName() const override;
      private:
        CStringObject *object_;
    };
} // namespace Expr
