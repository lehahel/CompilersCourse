#pragma once

#include <string>

class CType {
  public:
    virtual std::string get_type() const = 0;
};