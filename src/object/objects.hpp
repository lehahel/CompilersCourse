#pragma once

#include "type/types_fwd.hpp"
#include <type/types.hpp>

#include <fwd.hpp>

#include <type_traits>
#include <string>

#define CREATE_OBJECT(name, valueType, typeName)                    \
class name : public TBaseObject {                                   \
public:                                                             \
    explicit name(valueType val)                                    \
        : TBaseObject(NTypes::MakeType((typeName))), value_(val) {} \
    std::string ToString() const override {                         \
        return ToStringImpl(value_);                                \
    }                                                               \
    valueType GetValue() const {                                    \
        return value_;                                              \
    }                                                               \
private:                                                            \
    valueType value_;                                               \
};

namespace NObjects {

struct TCustomObjectValue {};

namespace {
    template <typename T>
    std::string ToStringImpl(T&& val) {
        if constexpr (std::is_same_v<std::decay_t<T>, std::string>) {
            return val;
        } else if constexpr (std::is_same_v<std::decay_t<T>, TCustomObjectValue>) {
            return "CustomObject";
        } else {
            return std::to_string(val);
        }
    }
} // namespace

class TBaseObject {
public:
    explicit TBaseObject(NTypes::TTypePtr&& type) : type_(std::move(type)) {};
    virtual std::string ToString() const = 0;
    NTypes::ETypeName GetTypeName() const {
        return type_->GetTypeName();
    }
    ~TBaseObject() {};
private:
    NTypes::TTypePtr type_;
};

CREATE_OBJECT(TBooleanObject, bool, NTypes::ETypeName::Boolean);
CREATE_OBJECT(TIntegerObject, std::int64_t, NTypes::ETypeName::Integer);
CREATE_OBJECT(TStringObject, std::string, NTypes::ETypeName::String);
CREATE_OBJECT(TDoubleObject, double, NTypes::ETypeName::Double);
CREATE_OBJECT(TCustomObject, TCustomObjectValue, NTypes::ETypeName::Custom);

} // namespace NObjects