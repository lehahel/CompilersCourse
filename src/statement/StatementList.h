#pragma once

#include "Statement.h"
#include <vector>

namespace Statement {
    class CList {
      public:
        CList() = default;
        virtual void Accept(Visitor::CBase *visitor);
        void Append(Statement::CBase *statement);
        std::vector<Statement::CBase *> list_;
    };
};