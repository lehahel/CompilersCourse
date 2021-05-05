#pragma once

#include <ForwardDeclarations.h>
#include <Base.h>
#include <type/Type.h>
#include <object/Object.hpp>
#include <string>

namespace Statement {
    class CBase : public CBaseNonterminal {
      public:
        virtual void Accept(Visitor::CBase *visitor) = 0;
    };
};
