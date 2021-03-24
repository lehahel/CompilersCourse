#include "Interpreter.h"

Visitor::CInterpreter::CInterpreter() {
    variables_["one"] = new CIntObject(1);
    variables_["two"] = new CIntObject(2);
    is_tos_expression_ = false;
    tos_value_ = nullptr;
}

void Visitor::CInterpreter::Visit(Program *program) {

}

void Visitor::CInterpreter::Visit(CMain *main_class) {

}

void Visitor::CInterpreter::Visit(Expr::CIntExpr *expression) {
    SetTosValue(&(expression->GetValue()));
}

void Visitor::CInterpreter::Visit(Expr::CDoubleExpr *expression) {
}

void Visitor::CInterpreter::Visit(Expr::CBoolExpr *expression) {
}

void Visitor::CInterpreter::Visit(Expr::CStringExpr *expression) {
}

void Visitor::CInterpreter::Visit(Expr::CBinaryOperation *expression) {
}

void Visitor::CInterpreter::Visit(Expr::CUnaryOperation *expression) {
}

void Visitor::CInterpreter::Visit(Statement::CExpr *statement) {
}

void Visitor::CInterpreter::Visit(Statement::CList *statements) {
}

void Visitor::CInterpreter::Visit(Statement::CAssignment *statement) {
}

void Visitor::CInterpreter::Visit(Lvalue::CIdentifier *identifier) {
}