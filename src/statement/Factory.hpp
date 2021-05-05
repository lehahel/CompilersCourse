#pragma once

#include "Statement.h"

#include "AssStatement.h"
#include "ExprStatement.h"
#include "LocVarDeclStatement.h"

#include "StatementList.h"

namespace Statement {
    CBase *CreateAssignment(Lvalue::CBase *id, Expr::CBase *value) {
        return new CAssignment(id, value);
    }

    CBase *CreateExpression(Expr::CBase *expr) {
        return new CExpr(expr);
    }

    CBase *CreateLocVarDecl(Declaration::CVarDecl *decl) {
        return new CLocVarDecl(decl);
    }

    CList *CreateList() {
        return new CList();
    }

};
