#pragma once

#include "Object.hpp"
#include <type/Type.h>
#include <type/String.hpp>

#include <string>

class CStringObject : public CObject {
  public:
    explicit CStringObject(const std::string &val)
        : CObject(new Type::CString()), value(val) {};
    std::string ToString() const override {
        return value;
    }
    std::string value;
};