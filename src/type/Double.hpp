#pragma once

#include "type/Type.h"

struct CDouble : public CType {
    CDouble() : CType(CType::TypeName::DOUBLE) {};
};