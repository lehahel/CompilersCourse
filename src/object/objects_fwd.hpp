#pragma once

#include <memory>

namespace NObjects {

class TBaseObject;
class TBooleanObject;
class TIntegerObject;
class TDoubleObject;
class TStringObject;
class TCustomObject;

using TObjectUniquePtr = std::unique_ptr<TBaseObject>;
using TObjectPtr = std::shared_ptr<TBaseObject>;

} // namespace NObjects
