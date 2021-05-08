#pragma once

#include "type/Type.h"

#include <string>

namespace Type {

const std::string DOUBLE_STR = "Type: double";

class CDouble : public CBase {
  public:
    CDouble() : CBase(Type::Name::DOUBLE) {};
    void Accept(Visitor::CBase *visitor) override {
        visitor->Visit(this);
    }
    std::string ToString() const override {
        return DOUBLE_STR;
    }
};
} // namespace Type