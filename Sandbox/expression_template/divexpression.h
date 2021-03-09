#pragma once

#include <memory>
#include "expression.h"

template <typename T, typename Left, typename Right>
class CDivExpression : public CExpression<T> {
public:
    CDivExpression(std::shared_ptr<CExpression<Left>>  left,
                   std::shared_ptr<CExpression<Right>> right);
    T eval() const override;

private:
    std::shared_ptr<CExpression<Left>>  left;
    std::shared_ptr<CExpression<Right>> right;
};
