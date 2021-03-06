#pragma once

#include <ForwardDeclarations.h>

#include "Statement.h"

namespace Statement {

    const std::string ASSIGNMENT_STR = "Assignment";

    class CAssignment : public CBase {
      public:
        CAssignment(Lvalue::CBase *identifier, Expr::CBase *expr);
        void Accept(Visitor::CBase *visitor) override;
        std::string ToString() const override;
    
        Lvalue::CBase *lvalue_;
        Expr::CBase *expr_;
    };
};
