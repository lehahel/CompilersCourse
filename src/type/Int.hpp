#pragma once

#include "type/Type.h"

struct CInt : public CType {
    CInt() : CType(CType::TypeName::INT) {};
};