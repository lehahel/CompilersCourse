#pragma once

#include <ForwardDeclarations.h>
#include <Program.h>

namespace Visitor {
    class CBase {
      public:
        virtual void Visit(Program *program) = 0;

        virtual void Visit(CMain *main_class) = 0;

        virtual void Visit(Expr::CIdent           *expression) = 0;
        virtual void Visit(Expr::CIntExpr         *expression) = 0;
        virtual void Visit(Expr::CDoubleExpr      *expression) = 0;
        virtual void Visit(Expr::CStringExpr      *expression) = 0;
        virtual void Visit(Expr::CBoolExpr        *expression) = 0;
        virtual void Visit(Expr::CBinaryOperation *expression) = 0;
        virtual void Visit(Expr::CUnaryOperation  *expression) = 0;

        virtual void Visit(Statement::CExpr       *statement)  = 0;
        virtual void Visit(Statement::CAssignment *statement)  = 0;
        virtual void Visit(Statement::CLocVarDecl *statements) = 0;
        virtual void Visit(Statement::CList       *statements) = 0;

        virtual void Visit(Declaration::CVarDecl  *declaration) = 0;
        
        virtual void Visit(CBool    *value) = 0;
        virtual void Visit(CDouble  *value) = 0;
        virtual void Visit(CInt     *value) = 0;
        virtual void Visit(CString  *value) = 0;

        virtual void Visit(Lvalue::CIdentifier *identifier) = 0;
    };
};