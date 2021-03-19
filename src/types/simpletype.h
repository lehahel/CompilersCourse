#pragma once

#include <string>

#include "type.h"

class CSimpleType : public CType{
  public:
    CSimpleType(const std::string &type);
    std::string get_type() const override;
  private:
    std::string type_name_;
};