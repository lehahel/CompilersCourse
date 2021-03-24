#include "VarDeclaration.h"

Declaration::CVarDecl::CVarDecl(CType *type, std::string var_name) 
    : type_(type), var_name_(var_name) {};

void Declaration::CVarDecl::Accept(Visitor::CBase *visitor) {
    visitor->Visit(this);
}

std::string Declaration::CVarDecl::ToString() const {
    return var_name_;
}