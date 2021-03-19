#include "arraytype.h"

CArrayType::CArrayType(const std::string &type)
  : type_name_(type) {};

std::string CArrayType::get_type() const {
    return type_name_;
}