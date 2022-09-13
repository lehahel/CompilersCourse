#include "types.hpp"

#include <memory>

NTypes::TTypePtr NTypes::MakeType(ETypeName typeName) noexcept {
    switch (typeName) {
        case ETypeName::Void    : return std::make_unique<TVoid>();
        case ETypeName::Boolean : return std::make_unique<TVoid>();
        case ETypeName::Integer : return std::make_unique<TVoid>();
        case ETypeName::Double  : return std::make_unique<TVoid>();
        case ETypeName::String  : return std::make_unique<TVoid>();
        case ETypeName::Custom  : return std::make_unique<TVoid>();
        default: return nullptr;
    }
}
