#pragma once

#include <ForwardDeclarations.h>
// #include <expression/Expression.h>

#include "Statement.h"

namespace Statement {
    class CExpr : public CBase {
      public:
        void Accept(Visitor::CBase *visitor) override;
        CExpr(Expr::CBase *expr);
        std::string ToString() const override;

        Expr::CBase *expr_;
    };
};