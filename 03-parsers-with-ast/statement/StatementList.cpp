#include "StatementList.h"

void Statement::CList::Append(Statement::CBase *statement) {
    list_.emplace_back(statement);
}

void Statement::CList::Accept(Visitor::CBase *visitor) {
    for (auto *statement : list_) {
        statement->Accept(visitor);
    }
}