#pragma once

#include "Object.hpp"
#include <type/Type.h>
#include <type/Bool.hpp>

class CBoolObject : public CObject {
  public:
    explicit CBoolObject(bool val)
    : CObject(new Type::CBool()), value(val) {};
    std::string ToString() const override {
        return std::to_string(value);
    }
    bool value;
};