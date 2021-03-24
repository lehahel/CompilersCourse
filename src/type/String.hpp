#pragma once

#include "type/Type.h"

class CString : public CType {
  public:
    CString() : CType(CType::TypeName::STRING) {};
    void Accept(Visitor::CBase *visitor) override {
        visitor->Visit(this);
    }
    std::string ToString() const override {
        return "string";
    }
};
