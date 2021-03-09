#pragma once

#include "assignment.h"

#include <vector>

class CAssignmentList {
  public:
    void append(CAssignment *assignment);

  private:
    std::vector<CAssignment *> list_;
};