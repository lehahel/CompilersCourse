#pragma once

enum ObjectType {
    BOOL_T   = 0,
    INT_T    = 1,
    DOUBLE_T = 2,
    STRING_T = 3,
    CUSTOM_T = 4
};

class CObject {
  public:
    virtual ObjectType get_type() const = 0;
};