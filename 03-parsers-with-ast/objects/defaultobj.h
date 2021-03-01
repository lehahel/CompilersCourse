#pragma once

#include "declarations/vardecl.h"
#include "object.h"

#include <string>
#include <vector>

const std::string TRUE = "YES";
const std::string FALSE = "NO";

class CBoolObject : public CObject {
  public:
    CBoolObject(const std::string &val);
    ObjectType get_type() const override;
  private:
    bool value_;
};

class CIntObject : public CObject {
  public:
    CIntObject(int val);
    ObjectType get_type() const override;
  private:
    int value_;
};

class CDoubleObject : public CObject {
  public:
    CDoubleObject(double val);
    ObjectType get_type() const override;
  private:
    double value_;
};

class CStringObject : public CObject {
  public:
    CStringObject(const std::string &value);
    ObjectType get_type() const override;
  private:
    std::string &value;
};

class CCustomObject : public CObject {
  public:
    CCustomObject(CVari)
  private:

};