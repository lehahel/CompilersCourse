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
        virtual std::string GetExprName() const = 0;
        CType *type;
        std::shared_ptr<CObject> object; 
    };
}
