#pragma once

#include <ForwardDeclarations.h>
// #include <expression/Expression.h>

#include "Statement.h"

namespace Statement {

    const std::string EXPR_STMT_STR = "ExprStatement";
    class CExpr : public CBase {
      public:
        CExpr(Expr::CBase *expr);
        void Accept(Visitor::CBase *visitor) override;
        std::string ToString() const override;

        Expr::CBase *expr_;
    };
};
