#pragma once

#include <ForwardDeclarations.h>
#include "Expression.h"
#include <visitor/Visitor.h>

namespace Expr {
    enum UnaryOperatorType {
        MINUS,
        NOT
    };

    class CUnaryOperation : public Expr::CBase {
      public:
        void Accept(Visitor::CBase *visitor) override;
        CUnaryOperation(
            UnaryOperatorType type,
            Expr::CBase *expr
        );
        ~CUnaryOperation() override = default;
        std::string GetExprName() const override;

        static CUnaryOperation *CreateMinus(Expr::CBase *expr);
        static CUnaryOperation *CreateNot  (Expr::CBase *expr);

        Expr::CBase *expr_;
      private:
        UnaryOperatorType type_;
    };
}
