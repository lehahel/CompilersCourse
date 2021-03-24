#pragma once

#include "type/Type.h"

class CInt : public CType {
  public:
    CInt() : CType(CType::TypeName::INT) {};
    void Accept(Visitor::CBase *visitor) override {
        visitor->Visit(this);
    }
    std::string ToString() const override {
        return "int";
    }
};