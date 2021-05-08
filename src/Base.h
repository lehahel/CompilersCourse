#pragma once

#include <visitor/Visitor.h>
#include "location.hh"

#include <string>

class CBaseNonterminal {
  public:
    virtual void Accept(Visitor::CBase *visitor) = 0;
    virtual ~CBaseNonterminal() = default;
    virtual std::string ToString() const = 0;
  
  private:
    yy::location loc;
};
