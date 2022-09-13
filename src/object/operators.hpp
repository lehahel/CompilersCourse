#pragma once

#include "object/objects_fwd.hpp"
#include <object/objects.hpp>

namespace NObjects::NOperators {

TObjectUniquePtr Add(TObjectPtr lhs, TObjectPtr rhs);
TObjectUniquePtr Sub(TObjectPtr lhs, TObjectPtr rhs);
TObjectUniquePtr Mul(TObjectPtr lhs, TObjectPtr rhs);
TObjectUniquePtr Div(TObjectPtr lhs, TObjectPtr rhs);

TObjectUniquePtr Less    (TObjectPtr lhs, TObjectPtr rhs);
TObjectUniquePtr Greater (TObjectPtr lhs, TObjectPtr rhs);
TObjectUniquePtr Leq     (TObjectPtr lhs, TObjectPtr rhs);
TObjectUniquePtr Geq     (TObjectPtr lhs, TObjectPtr rhs);
TObjectUniquePtr Eq      (TObjectPtr lhs, TObjectPtr rhs);
TObjectUniquePtr Neq     (TObjectPtr lhs, TObjectPtr rhs);

TObjectUniquePtr Minus (TObjectPtr obj);
TObjectUniquePtr Not   (TObjectPtr obj);

} // namespace NObjects::NOperators