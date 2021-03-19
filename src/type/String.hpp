#pragma once

#include "type/Type.h"

struct CString : public CType {
    CString() : CType(CType::TypeName::STRING) {};
};
