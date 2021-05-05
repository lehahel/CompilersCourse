#pragma once

#include <ForwardDeclarations.h>
#include "Declaration.h"
#include "VarDeclaration.h"

#include <string>

namespace Declaration {

CBase *CreateVarDecl(Type::CBase *type, const std::string &name) {
    return new CVarDecl(type, name);
}

};

