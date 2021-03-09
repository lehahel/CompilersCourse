#pragma once

#include "Object.hpp"
#include <type/Type.h>
#include <type/Bool.hpp>

class CBoolObject : public CObject {
  public:
    explicit CBoolObject(bool val)
    : CObject(new CBool()), value_(val) {};
  private:
    bool value_;
};