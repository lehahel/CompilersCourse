#include "MainClass.h"

CMain::CMain(Statement::CList *list) : list_(list) {};

void CMain::Accept(Visitor::CBase *visitor) {
    visitor->Visit(this);
}

std::string CMain::ToString() const {
    return "MainClass";
}