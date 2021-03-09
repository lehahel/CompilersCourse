#pragma once

#include "visitor/Visitor.h"
#include "location.hh"

class CBaseNonterminal {
  public:
    virtual void Accept(Visitor::Base *visitor) = 0;
    virtual ~CBaseNonterminal() = default;
  
  private:
    yy::location loc;
};