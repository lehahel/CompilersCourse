#pragma once

#include <ForwardDeclarations.h>
// #include "assignments/AssignmentList.h"
// #include "statement/Statement.h"
// #include "statement/StatementList.h"

// #include <MainClass.h>

class Program {
 public:
    Program(CMain *main_class);
  
    // Program(AssignmentList* assignments, Expression* expression);
    CMain *main_class_;
 private:
};