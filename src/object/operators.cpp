#include "operators.hpp"
#include "object/objects.hpp"
#include "object/objects_fwd.hpp"
#include "type/types.hpp"
#include "type/types_fwd.hpp"
#include <cstdlib>
#include <functional>
#include <memory>
#include <string>
#include <type_traits>

using NObjects::TObjectPtr;
using NObjects::TObjectUniquePtr;

using NObjects::TIntegerObject;
using NObjects::TDoubleObject;
using NObjects::TStringObject;
using NObjects::TBooleanObject;

namespace {

    template <typename Operator, typename Lhs, typename Rhs>
    struct OperatorValidator {
        template <typename InnerOperator, typename InnerLhs, typename InnerRhs>
        static consteval decltype(std::declval<InnerOperator>()(std::declval<InnerLhs>(), std::declval<InnerRhs>()), std::true_type{})
        Detector(std::remove_reference_t<Operator>*, std::remove_reference_t<Lhs>, std::remove_reference_t<Rhs>);

        template <typename InnerOperator, typename InnerLhs, typename InnerRhs>
        static consteval std::false_type Detector(...);

        using type = decltype(Detector<Operator, Lhs, Rhs>(nullptr, nullptr, nullptr));
        static constexpr bool value { type::value };
    };

    enum class BinaryOperationType { Add, Sub, Mul, Div, Less, Greater, Leq, Geq, Neq, Eq };

    template <typename Operator, typename Lhs, typename Rhs>
    TObjectUniquePtr CreateResult(Lhs lhs, Rhs rhs, Operator op) {
        auto result = op(lhs->GetValue(), rhs->GetValue());
        using ResultType = std::decay_t<decltype(result)>;
        if constexpr (std::is_same_v<ResultType, bool>) {
            auto resultPtr = new TBooleanObject(result);
            return TObjectUniquePtr(resultPtr);
        } else if constexpr (std::is_integral_v<ResultType>) {
            auto resultPtr = new TIntegerObject(result);
            return TObjectUniquePtr(resultPtr);
        } else if constexpr (std::is_same_v<ResultType, std::string>) {
            auto resultPtr = new TStringObject(result);
            return TObjectUniquePtr(resultPtr);
        } else if constexpr (std::is_floating_point_v<ResultType>) {
            auto resultPtr = new TDoubleObject(result);
            return TObjectUniquePtr(resultPtr);
        }
        std::abort();
    }

    template <typename Operator, typename Value>
    TObjectUniquePtr CreateResult(Value value, Operator op) {
        auto result = op(value->GetValue());
        using ResultType = std::decay_t<decltype(result)>;
        if constexpr (std::is_same_v<ResultType, bool>) {
            auto resultPtr = new TBooleanObject(result);
            return TObjectUniquePtr(resultPtr);
        } else if constexpr (std::is_integral_v<ResultType>) {
            auto resultPtr = new TIntegerObject(result);
            return TObjectUniquePtr(resultPtr);
        } else if constexpr (std::is_same_v<ResultType, std::string>) {
            auto resultPtr = new TStringObject(result);
            return TObjectUniquePtr(resultPtr);
        } else if constexpr (std::is_floating_point_v<ResultType>) {
            auto resultPtr = new TDoubleObject(result);
            return TObjectUniquePtr(resultPtr);
        }
        std::abort();
    }

    template <typename Operator>
    TObjectUniquePtr PerformIntegerBinaryOperation(TObjectPtr lhs, TObjectPtr rhs, Operator op) {
        auto castedLhs = dynamic_cast<TIntegerObject*>(lhs.get());
        auto castedRhs = dynamic_cast<TIntegerObject*>(rhs.get());
        return CreateResult(castedLhs, castedRhs, op);
    }

    template <typename Operator>
    TObjectUniquePtr PerformDoubleBinaryOperation(TObjectPtr lhs, TObjectPtr rhs, Operator op) {
        auto castedLhs = dynamic_cast<TDoubleObject*>(lhs.get());
        auto castedRhs = dynamic_cast<TDoubleObject*>(rhs.get());
        return CreateResult(castedLhs, castedRhs, op);
    }

    template <typename Operator>
    TObjectUniquePtr PerformStringBinaryOperation(TObjectPtr lhs, TObjectPtr rhs, Operator op) {
        auto castedLhs = dynamic_cast<TStringObject*>(lhs.get());
        auto castedRhs = dynamic_cast<TStringObject*>(rhs.get());
        return CreateResult(castedLhs, castedRhs, op);
    }

    template <typename Operator>
    TObjectUniquePtr PerformBooleanBinaryOperation(TObjectPtr lhs, TObjectPtr rhs, Operator op) {
        auto castedLhs = dynamic_cast<TBooleanObject*>(lhs.get());
        auto castedRhs = dynamic_cast<TBooleanObject*>(rhs.get());
        return CreateResult(castedLhs, castedRhs, op);
    }

    template <typename Operator>
    TObjectUniquePtr PerformIntegerUnaryOperation(TObjectPtr value, Operator op) {
        auto castedValue = dynamic_cast<TIntegerObject*>(value.get());
        return CreateResult(castedValue, op);
    }

    template <typename Operator>
    TObjectUniquePtr PerformDoubleUnaryOperation(TObjectPtr value, Operator op) {
        auto castedValue = dynamic_cast<TDoubleObject*>(value.get());
        return CreateResult(castedValue, op);
    }

    template <typename Operator>
    TObjectUniquePtr PerformStringUnaryOperation(TObjectPtr value, Operator op) {
        auto castedValue = dynamic_cast<TStringObject*>(value.get());
        return CreateResult(castedValue, op);
    }

    template <typename Operator>
    TObjectUniquePtr PerformBooleanUnaryOperation(TObjectPtr value, Operator op) {
        auto castedValue = dynamic_cast<TBooleanObject*>(value.get());
        return CreateResult(castedValue, op);
    }

} // namespace

TObjectUniquePtr NObjects::NOperators::Add(TObjectPtr lhs, TObjectPtr rhs) {
    if (lhs->GetTypeName() == NTypes::ETypeName::Integer && rhs->GetTypeName() == NTypes::ETypeName::Integer) {
        return PerformIntegerBinaryOperation(lhs, rhs, [](int l, int r){ return l + r; });
    }
    if (lhs->GetTypeName() == NTypes::ETypeName::Double && rhs->GetTypeName() == NTypes::ETypeName::Double) {
        return PerformDoubleBinaryOperation(lhs, rhs, [](double l, double r){ return l + r; });
    }
    if (lhs->GetTypeName() == NTypes::ETypeName::String && rhs->GetTypeName() == NTypes::ETypeName::String) {
        return PerformStringBinaryOperation(lhs, rhs, [](std::string l, std::string r){ return l + r; });
    }
    std::abort();
}

TObjectUniquePtr NObjects::NOperators::Sub(TObjectPtr lhs, TObjectPtr rhs) {
    if (lhs->GetTypeName() == NTypes::ETypeName::Integer && rhs->GetTypeName() == NTypes::ETypeName::Integer) {
        return PerformIntegerBinaryOperation(lhs, rhs, [](int l, int r){ return l - r; });
    }
    if (lhs->GetTypeName() == NTypes::ETypeName::Double && rhs->GetTypeName() == NTypes::ETypeName::Double) {
        return PerformDoubleBinaryOperation(lhs, rhs, [](double l, double r){ return l - r; });
    }
    std::abort();
}

TObjectUniquePtr NObjects::NOperators::Mul(TObjectPtr lhs, TObjectPtr rhs) {
    if (lhs->GetTypeName() == NTypes::ETypeName::Integer && rhs->GetTypeName() == NTypes::ETypeName::Integer) {
        return PerformIntegerBinaryOperation(lhs, rhs, [](int l, int r){ return l * r; });
    }
    if (lhs->GetTypeName() == NTypes::ETypeName::Double && rhs->GetTypeName() == NTypes::ETypeName::Double) {
        return PerformDoubleBinaryOperation(lhs, rhs, [](double l, double r){ return l * r; });
    }
    std::abort();
}

TObjectUniquePtr NObjects::NOperators::Div(TObjectPtr lhs, TObjectPtr rhs) {
    if (lhs->GetTypeName() == NTypes::ETypeName::Integer && rhs->GetTypeName() == NTypes::ETypeName::Integer) {
        return PerformIntegerBinaryOperation(lhs, rhs, [](int l, int r){ return l / r; });
    }
    if (lhs->GetTypeName() == NTypes::ETypeName::Double && rhs->GetTypeName() == NTypes::ETypeName::Double) {
        return PerformDoubleBinaryOperation(lhs, rhs, [](double l, double r){ return l / r; });
    }
    std::abort();
}

TObjectUniquePtr NObjects::NOperators::Less(TObjectPtr lhs, TObjectPtr rhs) {
    if (lhs->GetTypeName() == NTypes::ETypeName::Integer && rhs->GetTypeName() == NTypes::ETypeName::Integer) {
        return PerformIntegerBinaryOperation(lhs, rhs, [](int l, int r){ return l < r; });
    }
    if (lhs->GetTypeName() == NTypes::ETypeName::Double && rhs->GetTypeName() == NTypes::ETypeName::Double) {
        return PerformDoubleBinaryOperation(lhs, rhs, [](double l, double r){ return l < r; });
    }
    std::abort();
}

TObjectUniquePtr NObjects::NOperators::Greater(TObjectPtr lhs, TObjectPtr rhs) {
    if (lhs->GetTypeName() == NTypes::ETypeName::Integer && rhs->GetTypeName() == NTypes::ETypeName::Integer) {
        return PerformIntegerBinaryOperation(lhs, rhs, [](int l, int r){ return l > r; });
    }
    if (lhs->GetTypeName() == NTypes::ETypeName::Double && rhs->GetTypeName() == NTypes::ETypeName::Double) {
        return PerformDoubleBinaryOperation(lhs, rhs, [](double l, double r){ return l > r; });
    }
    std::abort();
}

TObjectUniquePtr NObjects::NOperators::Leq(TObjectPtr lhs, TObjectPtr rhs) {
    if (lhs->GetTypeName() == NTypes::ETypeName::Integer && rhs->GetTypeName() == NTypes::ETypeName::Integer) {
        return PerformIntegerBinaryOperation(lhs, rhs, [](int l, int r){ return l <= r; });
    }
    if (lhs->GetTypeName() == NTypes::ETypeName::Double && rhs->GetTypeName() == NTypes::ETypeName::Double) {
        return PerformDoubleBinaryOperation(lhs, rhs, [](double l, double r){ return l <= r; });
    }
    std::abort();
}

TObjectUniquePtr NObjects::NOperators::Geq(TObjectPtr lhs, TObjectPtr rhs) {
    if (lhs->GetTypeName() == NTypes::ETypeName::Integer && rhs->GetTypeName() == NTypes::ETypeName::Integer) {
        return PerformIntegerBinaryOperation(lhs, rhs, [](int l, int r){ return l >= r; });
    }
    if (lhs->GetTypeName() == NTypes::ETypeName::Double && rhs->GetTypeName() == NTypes::ETypeName::Double) {
        return PerformDoubleBinaryOperation(lhs, rhs, [](double l, double r){ return l >= r; });
    }
    std::abort();
}

TObjectUniquePtr NObjects::NOperators::Eq(TObjectPtr lhs, TObjectPtr rhs) {
    if (lhs->GetTypeName() == NTypes::ETypeName::Integer && rhs->GetTypeName() == NTypes::ETypeName::Integer) {
        return PerformIntegerBinaryOperation(lhs, rhs, [](int l, int r){ return l == r; });
    }
    if (lhs->GetTypeName() == NTypes::ETypeName::Double && rhs->GetTypeName() == NTypes::ETypeName::Double) {
        return PerformDoubleBinaryOperation(lhs, rhs, [](double l, double r){ return l == r; });
    }
    if (lhs->GetTypeName() == NTypes::ETypeName::String && rhs->GetTypeName() == NTypes::ETypeName::String) {
        return PerformStringBinaryOperation(lhs, rhs, [](std::string l, std::string r){ return l == r; });
    }
    if (lhs->GetTypeName() == NTypes::ETypeName::Boolean && rhs->GetTypeName() == NTypes::ETypeName::Boolean) {
        return PerformBooleanBinaryOperation(lhs, rhs, [](bool l, bool r){ return l == r; });
    }
    std::abort();
}

TObjectUniquePtr NObjects::NOperators::Neq(TObjectPtr lhs, TObjectPtr rhs) {
    if (lhs->GetTypeName() == NTypes::ETypeName::Integer && rhs->GetTypeName() == NTypes::ETypeName::Integer) {
        return PerformIntegerBinaryOperation(lhs, rhs, [](int l, int r){ return l != r; });
    }
    if (lhs->GetTypeName() == NTypes::ETypeName::Double && rhs->GetTypeName() == NTypes::ETypeName::Double) {
        return PerformDoubleBinaryOperation(lhs, rhs, [](double l, double r){ return l != r; });
    }
    if (lhs->GetTypeName() == NTypes::ETypeName::String && rhs->GetTypeName() == NTypes::ETypeName::String) {
        return PerformStringBinaryOperation(lhs, rhs, [](std::string l, std::string r){ return l != r; });
    }
    if (lhs->GetTypeName() == NTypes::ETypeName::Boolean && rhs->GetTypeName() == NTypes::ETypeName::Boolean) {
        return PerformBooleanBinaryOperation(lhs, rhs, [](bool l, bool r){ return l != r; });
    }
    std::abort();
}

TObjectUniquePtr NObjects::NOperators::Minus(TObjectPtr obj) {
    if (obj->GetTypeName() == NTypes::ETypeName::Integer) {
        return PerformIntegerUnaryOperation(obj, [](int obj){ return -obj; });
    }
    if (obj->GetTypeName() == NTypes::ETypeName::Double) {
        return PerformDoubleUnaryOperation(obj, [](double obj){ return -obj; });
    }
    std::abort();
}

TObjectUniquePtr NObjects::NOperators::Not(TObjectPtr obj) {
    if (obj->GetTypeName() == NTypes::ETypeName::Boolean) {
        return PerformBooleanUnaryOperation(obj, [](bool obj){ return !obj; });
    }
    std::abort();
}
