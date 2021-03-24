#pragma once

#include <ForwardDeclarations.h>
#include <visitor/Visitor.h>

#include <string>

class CType {
  public:
    enum TypeName {
        VOID,
        BOOL,
        INT,
        DOUBLE,
        STRING,
        CUSTOM
    };
    TypeName get_type() const;
    explicit CType(TypeName type);
    virtual void Accept(Visitor::CBase *visitor) = 0;
    virtual std::string ToString() const = 0;
  private:
    TypeName type_;
};