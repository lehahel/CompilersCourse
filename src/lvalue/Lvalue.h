#pragma once

#include <ForwardDeclarations.h>
#include <Base.h>
#include <string>

namespace Lvalue {
    class CBase : CBaseNonterminal {
      public:
        virtual void Accept(Visitor::CBase *visitor) = 0;
        virtual std::string GetIdentifier() const = 0;
    };
};
