#pragma once

#include <type/Type.h>

class CObject {
  public:
    explicit CObject(CType *type) : type(type) {};
    virtual ~CObject() = default;
    CType *type;
};