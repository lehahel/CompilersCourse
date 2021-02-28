#include "identexpression.h"

CIdentExpression::CIdentExpression(const std::string &ident)
  : ident_(ident) {};

int CIdentExpression::eval() const {
    return 0;
}