#pragma once

#include "Expression.h"
#include <visitor/Visitor.h>

namespace Expr {
    class CNumber : public Expr::CBase {
      public:
        void Accept(Visitor::CBase *visitor) override;

        CNumber(int value);

        ~CNumber() override = default;

      private:
        int value_;
    };
}