#pragma once

#include <fwd.hpp>

#include <fstream>
#include <memory>
#include <string_view>

namespace NVisitors {

class TBaseVisitor {
public:
    virtual void Visit(NTypes::TBase*) = 0;
    ~TBaseVisitor() {};
};

class TPrintVisitor : public TBaseVisitor {
public:
    TPrintVisitor(std::string_view filename);
    void Visit(NTypes::TBase*) override;
    ~TPrintVisitor();
private:
    void PrintTabs();
    std::ofstream stream_;
    std::size_t numTabs_ = 0;
};

};