#pragma once

#include "Expression.h"
#include <object/IntObject.hpp>
#include <ForwardDeclarations.h>

#include <string>

namespace Expr {

    const std::string IDENT_EXPR_STR = "IdentExpression: ";

    class CIdent : public CBase {
      public:
        CIdent(const std::string &var_name);
        void Accept(Visitor::CBase *visitor) override;
        CObject *GetValue() const override;
        std::string ToString() const override;
        std::string var_name_;
      private:
    };
} // namespace Expr
