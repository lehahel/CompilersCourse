#pragma once

#include "Object.hpp"
#include <type/Type.h>
#include <type/Double.hpp>

class CDoubleObject : public CObject {
  public:
    explicit CDoubleObject(double val)
    : CObject(new CDouble()), value_(val) {};
  private:
    double value_;
};