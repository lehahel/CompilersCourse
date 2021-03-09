#pragma once

struct CType {
  enum class TypeName {
      VOID,
      BOOL,
      INT,
      DOUBLE,
      STRING,
      CUSTOM
  };
    TypeName get_type() const;
    explicit CType(TypeName type);
  private:
    TypeName type_;
};