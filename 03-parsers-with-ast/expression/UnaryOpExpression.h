#pragma once

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

        static CUnaryOperation *CreateMinus(Expr::CBase *expr);
        static CUnaryOperation *CreateNot  (Expr::CBase *expr);

      private:
        UnaryOperatorType type_;
        Expr::CBase *expr_;
    };
}
