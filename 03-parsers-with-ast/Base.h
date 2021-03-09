#pragma once

#include "visitor/Visitor.h"
#include "location.hh"

class CBaseNonterminal {
  public:
    virtual void Accept(Visitor::CBase *visitor) = 0;
    virtual ~CBaseNonterminal() = default;
  
  private:
    yy::location loc;
};