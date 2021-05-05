#pragma once

#include "type/Type.h"

#include <string>


namespace Type {

const std::string BOOL_STR = "Type: bool";

class CBool : public CBase {
  public:
    CBool() : CBase(Type::Name::BOOL) {};
    void Accept(Visitor::CBase *visitor) override {
        visitor->Visit(this);
    }
    std::string ToString() const override {
        return BOOL_STR;
    }
};
} // namespace Type