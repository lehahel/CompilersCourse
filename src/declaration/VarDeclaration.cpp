#include "VarDeclaration.h"
#include <string>

Declaration::CVarDecl::CVarDecl(Type::CBase *type, std::string var_name) 
    : type_(type), var_name_(var_name) {};

void Declaration::CVarDecl::Accept(Visitor::CBase *visitor) {
    visitor->Visit(this);
}

std::string Declaration::CVarDecl::ToString() const {
    return VAR_DECL_STR + var_name_;
}