#include "simpletype.h"

CSimpleType::CSimpleType(const std::string &type)
  : type_name_(type) {};

std::string CSimpleType::get_type() const {
    return type_name_;
}