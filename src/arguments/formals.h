#pragma once

#include "objects/object.h"

#include <string>
#include <vector>

struct Formal {
    ObjectType type;
    std::string id;
};

class CFormals {
  public:
    CFormals() = default;
    void append(Formal formal);
    Formal operator[](size_t idx) const;
    size_t get_size() const;
  private:
    std::vector<Formal> formals_;
};