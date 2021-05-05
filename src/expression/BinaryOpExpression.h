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


    const std::string ADD_EXPR_STR = "AddExpression";
    const std::string SUB_EXPR_STR = "SubExpression"; 
    const std::string MUL_EXPR_STR = "MulExpression"; 
    const std::string DIV_EXPR_STR = "DivExpression"; 
    
    const std::string BIGGER_EXPR_STR = "BiggerExpression";
    const std::string LESS_EXPR_STR   = "LessExpression";
    const std::string BEQUAL_EXPR_STR = "BequalExpression";
    const std::string LEQUAL_EXPR_STR = "LequalExpression";
    const std::string EQUAL_EXPR_STR  = "EqualExpression";
    const std::string NEQUAL_EXPR_STR = "NequalExpression";

    class CBinaryOperation : public Expr::CBase {
      public:
        void Accept(Visitor::CBase *visitor) override;
        CBinaryOperation(
            BinaryOperatorType type,
            Expr::CBase *left,
            Expr::CBase *right
        );
        ~CBinaryOperation() override = default;
        CObject *GetValue() const override;
        std::string ToString() const override;
      
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

        BinaryOperatorType type_;
      private:
    };
}
