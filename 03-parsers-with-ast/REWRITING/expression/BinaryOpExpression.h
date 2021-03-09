#pragma once

#include "Expression.h"
#include <visitor/Visitor.h>

namespace Expression {
    enum BinaryOperatorType {
        ADD,
        SUB,
        MUL,
        DIV,
        BIGGER,
        LESS,
        LEQUAL,
        BEQUAL,
        EQUAL,
        NEQUAL  
    };

    class CBinaryOperation : public Expression::CBase {
      public:
        void Accept(Visitor::CBase *visitor) override;
        CBinaryOperation(
            BinaryOperatorType type,
            Expression::CBase *left,
            Expression::CBase *right
        );
        ~CBinaryOperation() override = default;

        static CBinaryOperation *CreateAdd    (Expression::CBase *left, Expression::CBase *right);
        static CBinaryOperation *CreateSub    (Expression::CBase *left, Expression::CBase *right);
        static CBinaryOperation *CreateMul    (Expression::CBase *left, Expression::CBase *right);
        static CBinaryOperation *CreateDiv    (Expression::CBase *left, Expression::CBase *right);
        static CBinaryOperation *CreateBigger (Expression::CBase *left, Expression::CBase *right);
        static CBinaryOperation *CreateLess   (Expression::CBase *left, Expression::CBase *right);
        static CBinaryOperation *CreateLequal (Expression::CBase *left, Expression::CBase *right);
        static CBinaryOperation *CreateBequal (Expression::CBase *left, Expression::CBase *right);
        static CBinaryOperation *CreateEqual  (Expression::CBase *left, Expression::CBase *right);
        static CBinaryOperation *CreateNequal (Expression::CBase *left, Expression::CBase *right);


      private:
        BinaryOperatorType type_;
        Expression::CBase *left_;
        Expression::CBase *right_;
    };
}
