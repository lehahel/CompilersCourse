#pragma once

#include "type.h"

#include <string>

class CArrayType : public CType {
  public:
    CArrayType(const std::string &type);
    std::string get_type() const override;
  private:
    std::string type_name_;
};