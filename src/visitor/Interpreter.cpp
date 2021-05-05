#include "Interpreter.h"

#include <object/Operator.hpp>

#include <statement/StatementList.h>

Visitor::CInterpreter::CInterpreter() {
    variables_["one"] = new CIntObject(1);
    variables_["two"] = new CIntObject(2);
    is_tos_expression_ = false;
    tos_value_ = nullptr;
}

void Visitor::CInterpreter::SetTosValue(CObject *value) {
    tos_value_ = value;
}

void Visitor::CInterpreter::Visit(Program *program) {
    program->main_class_->Accept(this);
    for (std::pair<std::string, CObject *> var : variables_) {
        std::cout << var.first << " " << var.second->ToString() << std::endl;
    }
}

void Visitor::CInterpreter::Visit(CMain *main_class) {
    main_class->list_->Accept(this);
}

void Visitor::CInterpreter::Visit(Expr::CIntExpr *expression) {
    SetTosValue(expression->GetValue());
}

void Visitor::CInterpreter::Visit(Expr::CDoubleExpr *expression) {
    SetTosValue(expression->GetValue());
}

void Visitor::CInterpreter::Visit(Expr::CBoolExpr *expression) {
    SetTosValue(expression->GetValue());
}

void Visitor::CInterpreter::Visit(Expr::CStringExpr *expression) {
    SetTosValue(expression->GetValue());
}

void Visitor::CInterpreter::Visit(Expr::CIdent *expression) {
    SetTosValue(variables_[expression->var_name_]);
}

void Visitor::CInterpreter::Visit(Expr::CBinaryOperation *expression) {
    expression->left_->Accept(this);
    CObject *left_obj = tos_value_; 

    expression->right_->Accept(this);
    CObject *right_obj = tos_value_;
    
    switch (expression->type_)
    {
    case Expr::ADD:
        SetTosValue(Add(left_obj, right_obj));
        break;
    case Expr::SUB:
        SetTosValue(Sub(left_obj, right_obj));
        break;
    case Expr::MUL:
        SetTosValue(Mul(left_obj, right_obj));
        break;
    case Expr::DIV:
        SetTosValue(Div(left_obj, right_obj));
        break;
    case Expr::EQUAL:
        SetTosValue(Equal(left_obj, right_obj));
        break;
    case Expr::NEQUAL:
        SetTosValue(Nequal(left_obj, right_obj));
        break;
    case Expr::LESS:
        SetTosValue(Less(left_obj, right_obj));
        break;
    case Expr::BIGGER:
        SetTosValue(Bigger(left_obj, right_obj));
        break;
    case Expr::LEQUAL:
        SetTosValue(Lequal(left_obj, right_obj));
        break;
    case Expr::BEQUAL:
        SetTosValue(Bequal(left_obj, right_obj));
        break;
    default:
        break;
    }
}

void Visitor::CInterpreter::Visit(Expr::CUnaryOperation *expression) {
    expression->expr_->Accept(this);
    CObject *value = tos_value_;
    switch (expression->type_)
    {
    case Expr::MINUS:
        SetTosValue(UnaryMinus(value));
        break;
    case Expr::NOT:
        SetTosValue(Not(value));
        break;
    default:
        break;
    }
}

void Visitor::CInterpreter::Visit(Statement::CExpr *statement) {
    statement->expr_->Accept(this);
}

void Visitor::CInterpreter::Visit(Statement::CList *statements) {
    for (Statement::CBase *statement : statements->list_) {
        statement->Accept(this);
    }
}

void Visitor::CInterpreter::Visit(Statement::CAssignment *statement) {
    statement->expr_->Accept(this);
    variables_[statement->lvalue_->GetIdentifier()] = tos_value_;
}

void Visitor::CInterpreter::Visit(Lvalue::CIdentifier *identifier) {
    CObject *value = new CStringObject(identifier->GetIdentifier());
    SetTosValue(value);
}

void Visitor::CInterpreter::Visit(Statement::CLocVarDecl *statements) {
    // implementation
}

void Visitor::CInterpreter::Visit(Declaration::CVarDecl *declaration) {
    // implementation
}

void Visitor::CInterpreter::Visit(Type::CBool *value) {
    // implementation
}

void Visitor::CInterpreter::Visit(Type::CDouble *value) {
    // implementation
}

void Visitor::CInterpreter::Visit(Type::CInt *value) {
    // implementation
}

void Visitor::CInterpreter::Visit(Type::CString *value) {
    // implementation
}



