#include "Type.h"

Type::CBase::CBase(Type::Name type) 
    : type_(type) {};

Type::Name Type::CBase::get_type() const {
    return type_;
}