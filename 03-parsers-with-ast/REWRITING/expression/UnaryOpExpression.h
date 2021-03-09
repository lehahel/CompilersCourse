#pragma once

#include "Expression.h"
#include <visitor/Visitor.h>

namespace Expression {
    enum UnaryOperatorType {
        MINUS,
        NOT
    };

    class CUnaryOperation : public Expression::CBase {
      public:
        void Accept(Visitor::CBase *visitor) override;
        CUnaryOperation(
            UnaryOperatorType type,
            Expression::CBase *expr
        );
        ~CUnaryOperation() override = default;

        static CUnaryOperation *CreateMinus(Expression::CBase *expr);
        static CUnaryOperation *CreateNot  (Expression::CBase *expr);

      private:
        UnaryOperatorType type_;
        Expression::CBase *expr_;
    };
}
