#pragma once

#include "type/Type.h"

namespace Type {
const std::string STRING_STR = "Type: string";

class CString : public CBase {
  public:
    CString() : CBase(Type::Name::STRING) {};
    void Accept(Visitor::CBase *visitor) override {
        visitor->Visit(this);
    }
    std::string ToString() const override {
        return STRING_STR;
    }
};
} // namespace Type
