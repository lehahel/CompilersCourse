#pragma once

#include <type/Type.h>

class CObject {
  public:
    explicit CObject(Type::CBase *type) : type(type) {};
    virtual ~CObject() = default;
    virtual std::string ToString() const = 0;
    Type::CBase *type;
};
