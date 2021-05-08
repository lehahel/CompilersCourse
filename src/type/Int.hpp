#pragma once

#include "type/Type.h"

#include <string>

namespace Type {

const std::string INT_STR = "Type: int";

class CInt : public CBase {
  public:
    CInt() : CBase(Type::Name::INT) {};
    void Accept(Visitor::CBase *visitor) override {
        visitor->Visit(this);
    }
    std::string ToString() const override {
        return INT_STR;
    }
};
} // namespace Type;