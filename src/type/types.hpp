#pragma once

#include <fwd.hpp>
#include <visitor/visitor.hpp>

#include <memory>
#include <string>

#define CREATE_TYPE(name, typeName) \
class name : public TBase { \
public: \
    name() : TBase(typeName) {}; \
    std::string ToString() const override { return std::string("Type:") + #name; } \
    void AcceptVisitor(NVisitors::TVisitorPtr visitor) override { visitor->Visit(this); } \
}; \

namespace NTypes {

enum class ETypeName { Void, Boolean, Integer, Double, String, Custom };

class TBase  {
public:
    explicit constexpr TBase(ETypeName type) noexcept : type_(type) {};
    ETypeName GetTypeName() const noexcept { return type_; };
public:
    virtual void AcceptVisitor(NVisitors::TVisitorPtr) = 0;
    virtual std::string ToString() const = 0;
private:
    ETypeName type_;
};

CREATE_TYPE(TBoolean, ETypeName::Boolean);
CREATE_TYPE(TInteger, ETypeName::Integer);
CREATE_TYPE(TDouble, ETypeName::Double);
CREATE_TYPE(TString, ETypeName::String);
CREATE_TYPE(TVoid, ETypeName::Void);
CREATE_TYPE(TCustom, ETypeName::Custom);

TTypePtr MakeType(ETypeName typeName) noexcept;

} // namespace NTypes