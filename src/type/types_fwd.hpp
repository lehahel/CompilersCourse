#pragma once

#include <memory>

namespace NTypes {

class TBase;
class TBoolean;
class TInteger;
class TString;
class TDouble;
class TVoid;
class TCustom;

using TTypePtr = std::unique_ptr<TBase>;

} // namespace NTypes