#pragma once

#include "Object.hpp"
#include <type/Type.h>
#include <type/Int.hpp>

class CIntObject : public CObject {
  public:
    explicit CIntObject(int val)
    : CObject(new CInt()), value(val) {};
    int value;
};