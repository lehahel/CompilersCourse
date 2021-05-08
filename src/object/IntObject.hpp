#pragma once

#include "Object.hpp"
#include <type/Type.h>
#include <type/Int.hpp>

class CIntObject : public CObject {
  public:
    explicit CIntObject(int val)
    : CObject(new Type::CInt()), value(val) {};
    std::string ToString() const override {
        return std::to_string(value);
    }
    int value;
};