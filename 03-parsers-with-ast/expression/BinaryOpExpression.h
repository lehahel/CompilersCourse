#pragma once

#include <ForwardDeclarations.h>
#include "Expression.h"
#include <visitor/Visitor.h>

namespace Expr {
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

    class CBinaryOperation : public Expr::CBase {
      public:
        void Accept(Visitor::CBase *visitor) override;
        CBinaryOperation(
            BinaryOperatorType type,
            Expr::CBase *left,
            Expr::CBase *right
        );
        ~CBinaryOperation() override = default;
        std::string GetExprName() const override;
      
        static CBinaryOperation *CreateAdd    (Expr::CBase *left, Expr::CBase *right);
        static CBinaryOperation *CreateSub    (Expr::CBase *left, Expr::CBase *right);
        static CBinaryOperation *CreateMul    (Expr::CBase *left, Expr::CBase *right);
        static CBinaryOperation *CreateDiv    (Expr::CBase *left, Expr::CBase *right);
        static CBinaryOperation *CreateBigger (Expr::CBase *left, Expr::CBase *right);
        static CBinaryOperation *CreateLess   (Expr::CBase *left, Expr::CBase *right);
        static CBinaryOperation *CreateLequal (Expr::CBase *left, Expr::CBase *right);
        static CBinaryOperation *CreateBequal (Expr::CBase *left, Expr::CBase *right);
        static CBinaryOperation *CreateEqual  (Expr::CBase *left, Expr::CBase *right);
        static CBinaryOperation *CreateNequal (Expr::CBase *left, Expr::CBase *right);

        Expr::CBase *left_;
        Expr::CBase *right_;

      private:
        BinaryOperatorType type_;
    };
}
