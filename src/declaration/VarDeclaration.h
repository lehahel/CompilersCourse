#pragma once

#include <ForwardDeclarations.h>
#include "Declaration.h"
#include <type/Type.h>

#include <string>

namespace Declaration {
    class CVarDecl : public CBase {
      public:
        CVarDecl(CType *type, std::string var_name);
        void Accept(Visitor::CBase *visitor) override;
        std::string ToString() const override;   
      private:
        CType *type_;
        std::string var_name_;
    };
}