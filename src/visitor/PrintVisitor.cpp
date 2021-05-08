#include "PrintVisitor.h"
#include <statement/StatementList.h>
#include <statement/AssStatement.h>
#include <iostream>

const std::string SEPARATOR = ": ";
const std::string TAB = "\t";

Visitor::CPrinter::CPrinter(const std::string &filename)
  : stream_(filename) {};

Visitor::CPrinter::~CPrinter() {
    stream_.close();
}

void Visitor::CPrinter::PrintTabs() {
    for (size_t i = 0; i < num_tabs_; ++i) {
        stream_ << TAB;
    }
}

void Visitor::CPrinter::Visit(Expr::CIdent *expression) {
    PrintTabs();
    stream_ << expression->ToString() << std::endl;
}

void Visitor::CPrinter::Visit(Expr::CIntExpr *expression) {
    PrintTabs();
    stream_ << expression->ToString() << std::endl;
}

void Visitor::CPrinter::Visit(Expr::CDoubleExpr *expression) {
    PrintTabs();
    stream_ << expression->ToString() << std::endl;
}

void Visitor::CPrinter::Visit(Expr::CBoolExpr *expression) {
    PrintTabs();
    stream_ << expression->ToString() << std::endl;
}

void Visitor::CPrinter::Visit(Expr::CStringExpr *expression) {
    PrintTabs();
    stream_ << expression->ToString() << std::endl;
}

void Visitor::CPrinter::Visit(Lvalue::CIdentifier *identifier) {
    PrintTabs();
    stream_ << identifier->ToString() << std::endl;
}

void Visitor::CPrinter::Visit(Declaration::CVarDecl *declaration) {
    PrintTabs();
    stream_ << declaration->ToString() << std::endl;
}

void Visitor::CPrinter::Visit(Type::CBool *value) {
    PrintTabs();
    stream_ << value->ToString() << std::endl;
}

void Visitor::CPrinter::Visit(Type::CDouble *value) {
    PrintTabs();
    stream_ << value->ToString() << std::endl;
}

void Visitor::CPrinter::Visit(Type::CInt *value) {
    PrintTabs();
    stream_ << value->ToString() << std::endl;
}

void Visitor::CPrinter::Visit(Type::CString *value) {
    PrintTabs();
    stream_ << value->ToString() << std::endl;
}

void Visitor::CPrinter::Visit(Program *program) {
    program->main_class_->Accept(this);
}

void Visitor::CPrinter::Visit(CMain *main_class) {
    PrintTabs();
    stream_ << main_class->ToString() << SEPARATOR << std::endl;
    ++num_tabs_;
    main_class->list_->Accept(this);
    --num_tabs_;
}

void Visitor::CPrinter::Visit(Expr::CBinaryOperation *expression) {
    PrintTabs();
    stream_ << expression->ToString() << SEPARATOR << std::endl;
    ++num_tabs_;
    expression->left_->Accept(this);
    expression->right_->Accept(this);
    --num_tabs_;
}

void Visitor::CPrinter::Visit(Expr::CUnaryOperation *expression) {
    PrintTabs();
    stream_ << expression->ToString() << SEPARATOR << std::endl;
    ++num_tabs_;
    expression->expr_->Accept(this);
    --num_tabs_;
}

void Visitor::CPrinter::Visit(Statement::CExpr *statement) {
    PrintTabs();
    stream_ << statement->ToString() << SEPARATOR << std::endl;
    ++num_tabs_;
    statement->expr_->Accept(this);
    --num_tabs_;
}

void Visitor::CPrinter::Visit(Statement::CLocVarDecl *statement) {
    PrintTabs();
    stream_ << statement->ToString() << SEPARATOR << std::endl;
    ++num_tabs_;
    statement->loc_var_->Accept(this);
    --num_tabs_;
}

void Visitor::CPrinter::Visit(Statement::CList *statements) {
    PrintTabs();
    statements->Accept(this);
}

void Visitor::CPrinter::Visit(Statement::CAssignment *statement) {
    PrintTabs();
    stream_ << statement->ToString() << SEPARATOR << std::endl;
    ++num_tabs_;
    statement->lvalue_->Accept(this);
    statement->expr_->Accept(this);
    --num_tabs_;
}
