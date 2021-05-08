#pragma once

#include <ForwardDeclarations.h>
#include <visitor/Visitor.h>

#include <string>

namespace Type {

enum Name {
    VOID,
    BOOL,
    INT,
    DOUBLE,
    STRING,
    CUSTOM
};
class CBase {
  public:
    Name get_type() const;
    explicit CBase(Name type);
    virtual void Accept(Visitor::CBase *visitor) = 0;
    virtual std::string ToString() const = 0;
  private:
    Name type_;
};
} // namespace Type