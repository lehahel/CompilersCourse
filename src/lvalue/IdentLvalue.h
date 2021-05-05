#pragma once

#include "Lvalue.h"

namespace Lvalue {

    const std::string IDENT_STRING = "Identifier: ";

    class CIdentifier : public CBase {
      public:
        CIdentifier(std::string identifier);
        void Accept(Visitor::CBase *visitor) override;
        std::string ToString() const override;
        std::string GetIdentifier() const override;

        std::string identifier_;
    };
};
