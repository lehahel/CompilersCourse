#pragma once

#include "type/Type.h"

class CDouble : public CType {
  public:
    CDouble() : CType(CType::TypeName::DOUBLE) {};
    void Accept(Visitor::CBase *visitor) override {
        visitor->Visit(this);
    }
    std::string ToString() const override {
        return "double";
    }
};