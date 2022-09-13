#pragma once

#include <memory>

namespace NVisitors {

class TBaseVisitor;

using TVisitorPtr = std::shared_ptr<TBaseVisitor>;

} // namespace NVisitors
