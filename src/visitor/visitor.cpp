#include "visitor.hpp"

#include <type/types.hpp>

NVisitors::TPrintVisitor::TPrintVisitor(std::string_view filename)
    : stream_(filename) {}

void NVisitors::TPrintVisitor::PrintTabs() {
    for (std::size_t i = 0; i < numTabs_; ++i) {
        stream_ << "    ";
    }
}

NVisitors::TPrintVisitor::~TPrintVisitor() {
    stream_.close();
}

void NVisitors::TPrintVisitor::Visit(NTypes::TBase* term) {
    PrintTabs();
    stream_ << term->ToString() << std::endl;
}
