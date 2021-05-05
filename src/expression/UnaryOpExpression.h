#pragma once

#include <ForwardDeclarations.h>
#include "Expression.h"
#include <visitor/Visitor.h>

namespace Expr {
    enum UnaryOperatorType {
        MINUS,
        NOT
    };

    const std::string MINUS_EXPR_STR = "UnaryMinusExpression";
    const std::string NOT_EXPR_STR   = "NotExpression";

    class CUnaryOperation : public Expr::CBase {
      public:
        void Accept(Visitor::CBase *visitor) override;
        CUnaryOperation(
            UnaryOperatorType type,
            Expr::CBase *expr
        );
        ~CUnaryOperation() override = default;
        std::string ToString() const override;
        CObject *GetValue() const override;

        static CUnaryOperation *CreateMinus(Expr::CBase *expr);
        static CUnaryOperation *CreateNot  (Expr::CBase *expr);

        Expr::CBase *expr_;
        UnaryOperatorType type_;
      private:
    };
}
