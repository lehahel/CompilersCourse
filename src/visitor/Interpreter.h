#pragma once

#include "Visitor.h"

#include <expression/Expression.h>
#include <expression/IntExpression.h>
#include <expression/DoubleExpression.h>
#include <expression/BoolExpression.h>
#include <expression/StringExpression.h>
#include <expression/UnaryOpExpression.h>
#include <expression/BinaryOpExpression.h>
#include <expression/IdentExpression.h>

#include <statement/Statement.h>
#include <statement/StatementList.h>
#include <statement/ExprStatement.h>
#include <statement/AssStatement.h>

#include <lvalue/Lvalue.h>
#include <lvalue/IdentLvalue.h>

#include <MainClass.h>

#include <fstream>
#include <string>
#include <map>

namespace Visitor {
    class CInterpreter : public CBase {
      public:
        CInterpreter();
        // ~CInterpreter();
        
        void Visit(Program *program) override;

        void Visit(CMain *main_class) override;
        void Visit(Expr::CBinaryOperation *expression)  override;
        void Visit(Expr::CUnaryOperation  *expression)  override;
        void Visit(Statement::CExpr       *statement)   override;
        void Visit(Statement::CAssignment *statement)   override;
        void Visit(Statement::CLocVarDecl *statements)  override;
        void Visit(Statement::CList       *statements)  override;
        void Visit(Declaration::CVarDecl  *declaration) override;

        void Visit(Expr::CIdent           *expression) override;
        void Visit(Expr::CIntExpr         *expression) override;
        void Visit(Expr::CDoubleExpr      *expression) override;
        void Visit(Expr::CBoolExpr        *expression) override;
        void Visit(Expr::CStringExpr      *expression) override;

        void Visit(Type::CBool   *value) override;
        void Visit(Type::CDouble *value) override;
        void Visit(Type::CInt    *value) override;
        void Visit(Type::CString *value) override;
        void Visit(Lvalue::CIdentifier *identifier) override;

      private:
        std::map<std::string, CObject *> variables_;
        bool is_tos_expression_;
        CObject *tos_value_;

        void SetTosValue(CObject *value);
        void UnsetTosValue();
    };
}
