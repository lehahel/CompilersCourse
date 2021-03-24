#include "IdentExpression.h"

Expr::CIdent::CIdent(const std::string &var_name) : var_name_(var_name) {};

void Expr::CIdent::Accept(Visitor::CBase *visitor) {
    visitor->Visit(this);
}

int Expr::CIdent::GetValue() const {
    return 42;
}

std::string Expr::CIdent::GetExprName() const {
    return var_name_;
}
