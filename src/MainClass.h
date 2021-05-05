#pragma once

#include "ForwardDeclarations.h"
#include "Base.h"

#include <string>

const std::string MAIN_CLASS_STR = "MainClass";

class CMain : public CBaseNonterminal {
  public:
    CMain(Statement::CList *list);
    void Accept(Visitor::CBase *visitor);
    std::string ToString() const override;
    Statement::CList *list_;
  private:
};