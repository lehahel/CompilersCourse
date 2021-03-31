#include "PrintVisitor.h"
#include <statement/StatementList.h>
#include <statement/AssStatement.h>
#include <iostream>

Visitor::CPrinter::CPrinter(const std::string &filename)
  : stream_(filename) {};

Visitor::CPrinter::~CPrinter() {
    stream_.close();
}

void Visitor::CPrinter::Visit(Program *program) {
    program->main_class_->Accept(this);
}

void Visitor::CPrinter::Visit(CMain *main_class) {
    PrintTabs();
    stream_ << "MainClass: " << std::endl;
    ++num_tabs_;
    main_class->list_->Accept(this);
    --num_tabs_;
}

void Visitor::CPrinter::PrintTabs() {
    for (size_t i = 0; i < num_tabs_; ++i) {
        stream_ << '\t';
    }
}

void Visitor::CPrinter::Visit(Expr::CIntExpr *expression) {
    PrintTabs();
    stream_ << "IntExpression: " << expression->GetValue() << std::endl;
}

void Visitor::CPrinter::Visit(Expr::CDoubleExpr *expression) {
    PrintTabs();
    stream_ << "DoubleExpression: " << expression->GetValue() << std::endl;
}

void Visitor::CPrinter::Visit(Expr::CBoolExpr *expression) {
    PrintTabs();
    stream_ << "BoolExpression: " << expression->GetValue() << std::endl;
}

void Visitor::CPrinter::Visit(Expr::CStringExpr *expression) {
    PrintTabs();
    stream_ << "StringExpression: " << expression->GetValue() << std::endl;
}


void Visitor::CPrinter::Visit(Expr::CBinaryOperation *expression) {
    PrintTabs();
    stream_ << expression->GetExprName() << ": " << std::endl;
    ++num_tabs_;
    expression->left_->Accept(this);
    expression->right_->Accept(this);
    --num_tabs_;
}

void Visitor::CPrinter::Visit(Expr::CUnaryOperation *expression) {
    PrintTabs();
    stream_ << expression->GetExprName() << ": " << std::endl;
    ++num_tabs_;
    expression->expr_->Accept(this);
    --num_tabs_;
}

void Visitor::CPrinter::Visit(Statement::CExpr *statement) {
    PrintTabs();
    stream_ << statement->ToString() << ": " << std::endl;
    ++num_tabs_;
    statement->expr_->Accept(this);
    --num_tabs_;
}

void Visitor::CPrinter::Visit(Statement::CList *statements) {
    PrintTabs();
    statements->Accept(this);
}

void Visitor::CPrinter::Visit(Statement::CAssignment *statement) {
    PrintTabs();
    stream_ << statement->ToString() << ": " << std::endl;
    ++num_tabs_;
    statement->lvalue_->Accept(this);
    statement->expr_->Accept(this);
    --num_tabs_;
}

void Visitor::CPrinter::Visit(Lvalue::CIdentifier *identifier) {
    PrintTabs();
    stream_ << identifier->ToString() << std::endl;
}