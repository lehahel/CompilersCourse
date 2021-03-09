#pragma once

#include "type/Type.h"

struct CBool : public CType {
    CBool() : CType(CType::TypeName::BOOL) {};
};