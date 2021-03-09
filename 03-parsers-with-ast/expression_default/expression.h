#pragma once

#include "objects/object.h"
#include "objects/defaultobj.h"

template <typename T = CBoolObject>
class CExpression {
  public:
    virtual T eval() const;
};

template <typename T = CIntObject>
class CExpression {
  public:
    virtual T eval() const;
};

template <typename T = CIntObject>
class CExpression {
  public:
    virtual T eval() const;
};