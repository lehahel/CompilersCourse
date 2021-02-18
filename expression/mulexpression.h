#pragma once

#include <memory>
#include "expression.h"

template <typename T, typename Left, typename Right>
class CMulExpression : public CExpression<T> {
public:
    CMulExpression(std::shared_ptr<Left>  left,
                   std::shared_ptr<Right> right);
    T eval() const override;

private:
    std::shared_ptr<CExpression<Left>>  left;
    std::shared_ptr<CExpression<Right>> right;
};
