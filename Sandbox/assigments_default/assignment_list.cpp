#include "assignment_list.h"

void CAssignmentList::append(CAssignment *assignment) {
    list_.emplace_back(assignment);
}