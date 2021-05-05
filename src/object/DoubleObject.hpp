#pragma once

#include "Object.hpp"
#include <type/Type.h>
#include <type/Double.hpp>

class CDoubleObject : public CObject {
  public:
    explicit CDoubleObject(double val)
    : CObject(new Type::CDouble()), value(val) {};
    std::string ToString() const override {
        return std::to_string(value);
    }
    double value;
};