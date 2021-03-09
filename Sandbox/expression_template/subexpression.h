#pragma once

#include <memory>
#include "expression.h"

template <typename T, typename Left, typename Right>
class CSubExpression : public CExpression<T> {
public:
    CSubExpression(std::shared_ptr<CExpression<Left>>  left,
                   std::shared_ptr<CExpression<Right>> right);
    T eval() const override;

private:
    std::shared_ptr<CExpression<Left>>  left;
    std::shared_ptr<CExpression<Right>> right;
};
