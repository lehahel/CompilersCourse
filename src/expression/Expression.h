#pragma once

#include <ForwardDeclarations.h>
#include <Base.h>
#include <type/Type.h>
#include <object/Object.hpp>
#include <memory>
#include <string>

namespace Expr {
    class CBase : public CBaseNonterminal {
      public:
        virtual void Accept(Visitor::CBase *visitor) = 0;
        virtual CObject *GetValue() const = 0;
        Type::CBase *type;
        CObject *object;
    };
}
