#include "assignment.h"

CAssignment::CAssignment(
    const std::string &variable,
    CExpression *expression
) : variable_(variable), 
    expression_(expression) {}
