#include "LocVarDeclStatement.h"

Statement::CLocVarDecl::CLocVarDecl(Declaration::CVarDecl *loc_var) 
    : loc_var_(loc_var) {};

void Statement::CLocVarDecl::Accept(Visitor::CBase *visitor) {
    visitor->Visit(this);
}

std::string Statement::CLocVarDecl::ToString() const {
    return "LocVarDecl";
}