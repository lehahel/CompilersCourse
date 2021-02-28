#include "subexpression.h"

template <typename T, typename Left, typename Right>
CSubExpression<T, Left, Right>::CSubExpression(
    std::shared_ptr<Left>  left,
    std::shared_ptr<Right> right)
    : left (left),
      right(right) {};


template <typename T, typename Left, typename Right>
T CSubExpression<T, Left, Right>::eval() const {
    return first->eval() - second->eval();
}