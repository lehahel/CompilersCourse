#pragma once

#include <memory>

#include <Base.h>
#include <visitor/Visitor.h>
#include <type/Type.h>
#include <object/Object.hpp>

namespace Expr {
    class CBase : public CBaseNonterminal {
      public:
        CType *type;
        std::shared_ptr<CObject> object; 
    };
}