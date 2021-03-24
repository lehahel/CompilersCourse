#pragma once

#include "Expression.h"
#include <object/IntObject.hpp>
#include <ForwardDeclarations.h>

namespace Expr {
    class CIdent : public CBase {
      public:
        CIdent(const std::string &var_name);
        void Accept(Visitor::CBase *visitor) override;
        int GetValue() const;
        std::string GetExprName() const override;
      private:
        std::string var_name_;
    };
} // namespace Expr
