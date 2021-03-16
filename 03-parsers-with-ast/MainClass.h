#pragma once

#include "ForwardDeclarations.h"
#include "Base.h"

#include <string>

class CMain : public CBaseNonterminal {
  public:
    CMain(Statement::CList *list);
    void Accept(Visitor::CBase *visitor);
    std::string ToString() const;
    Statement::CList *list_;
  private:
};