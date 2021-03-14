#include "Visitor.h"
#include <expression/Expression.h>
#include <expression/IntExpression.h>
#include <expression/DoubleExpression.h>
#include <expression/BoolExpression.h>
#include <expression/StringExpression.h>
#include <expression/UnaryOpExpression.h>
#include <expression/BinaryOpExpression.h>

#include <fstream>
#include <string>


namespace Visitor {
    class CPrinter : public CBase {
      public:
        CPrinter(const std::string &filename);
        ~CPrinter();
        void Visit(Expr::CIntExpr    *expression) override;
        void Visit(Expr::CDoubleExpr *expression) override;
        void Visit(Expr::CBoolExpr   *expression) override;
        void Visit(Expr::CStringExpr *expression) override;

        void Visit(Expr::CBinaryOperation *expression) override;
        void Visit(Expr::CUnaryOperation  *expression) override;

      private:  
        void PrintTabs();
        std::ofstream stream_;
        size_t num_tabs_ = 0;
};
};