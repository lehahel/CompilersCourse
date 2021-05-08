#pragma once

#include "Statement.h"

namespace Statement {


    const std::string LOC_VAR_DECL_STR = "LocVarDecl";

    class CLocVarDecl : public CBase {
      public:
        void Accept(Visitor::CBase *visitor) override;
        CLocVarDecl(Declaration::CVarDecl *loc_var);
        std::string ToString() const override;

        Declaration::CVarDecl *loc_var_;
    };
}
