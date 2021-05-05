#include "IdentExpression.h"

Expr::CIdent::CIdent(const std::string &var_name) : var_name_(var_name) {};

void Expr::CIdent::Accept(Visitor::CBase *visitor) {
    visitor->Visit(this);
}

CObject *Expr::CIdent::GetValue() const {
    return nullptr;  // ;)
}

std::string Expr::CIdent::ToString() const {
    return IDENT_EXPR_STR + var_name_;
}
