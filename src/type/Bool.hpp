#pragma once

#include "type/Type.h"

class CBool : public CType {
  public:
    CBool() : CType(CType::TypeName::BOOL) {};
    void Accept(Visitor::CBase *visitor) override {
        visitor->Visit(this);
    }
    std::string ToString() const override {
        return "bool";
    }
};