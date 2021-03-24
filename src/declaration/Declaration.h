#pragma once

#include <Base.h>

namespace Declaration {
    class CBase : public CBaseNonterminal {
      public:
        virtual void Accept(Visitor::CBase *visitor) = 0;
        virtual std::string ToString() const = 0;        
    };
}