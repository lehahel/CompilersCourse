#pragma once

#include "Lvalue.h"
#include "IdentLvalue.h"

namespace Lvalue {

CBase *CreateIdent(const std::string &name) {
    return new CIdentifier(name);
}

};
