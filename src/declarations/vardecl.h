#pragma once

#include "types/type.h"
#include "types/simpletype.h"
#include "types/arraytype.h"

class CVariableDeclaration {
  public:
    CVariableDeclaration();
  private:
    CType *type_;
    std::string name_;
};
