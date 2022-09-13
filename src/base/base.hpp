#pragma once

#include "location.hh"
#include <visitor/visitor.hpp>

class TBaseNonTerminal {
public:
    virtual void Accept(NVisitors::TVisitorPtr visitor) = 0;
    virtual std::string ToString() const = 0;
    virtual ~TBaseNonTerminal() {};
private:
    yy::location loc;
};
