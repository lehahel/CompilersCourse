#pragma once

#include <ForwardDeclarations.h>
#include <Base.h>

#include <string>

class CAssignment : CBaseNonterminal {
  public:
    CAssignment(Lvalue::CIdentifier *variable, Expr::CBase *expr);

    void Accept(Visitor::CBase *visitor);
    std::string ToString() const;
    
    Lvalue::CIdentifier *identifier_;
    Expr::CBase *expr_;
};