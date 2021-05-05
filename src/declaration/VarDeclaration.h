#pragma once

#include <ForwardDeclarations.h>
#include "Declaration.h"
#include <type/Type.h>

#include <string>

namespace Declaration {

    const std::string VAR_DECL_STR = "VarDeclaration";
    
    class CVarDecl : public CBase {
      public:
        CVarDecl(Type::CBase *type, std::string var_name);
        void Accept(Visitor::CBase *visitor) override;
        std::string ToString() const override;   
      private:
        Type::CBase *type_;
        std::string var_name_;
    };
}