#pragma once

#include "Base.h"   
#include "type/Type.h"
#include <memory>

namespace Expression {
    class CBase : public CBaseNonterminal {
        CType *type;
        std::shared_ptr<Object> object;
    };
}