#include "Type.h"

CType::CType(TypeName type) 
    : type_(type) {};

CType::TypeName CType::get_type() const {
    return type_;
}