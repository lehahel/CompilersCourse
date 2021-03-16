#pragma once

#include <ForwardDeclarations.h>
// #include <expression/Expression.h>
// #include <expression/IntExpression.h>
// #include <expression/DoubleExpression.h>
// #include <expression/BoolExpression.h>
// #include <expression/StringExpression.h>
// #include <expression/UnaryOpExpression.h>
// #include <expression/BinaryOpExpression.h>

namespace Visitor {
    class CBase {
      public:
        virtual void Visit(Expr::CIntExpr    *expression) = 0;
        virtual void Visit(Expr::CDoubleExpr *expression) = 0;
        virtual void Visit(Expr::CStringExpr *expression) = 0;
        virtual void Visit(Expr::CBoolExpr   *expression) = 0;

        virtual void Visit(Expr::CBinaryOperation *expression) = 0;
        virtual void Visit(Expr::CUnaryOperation  *expression) = 0;
    };
};