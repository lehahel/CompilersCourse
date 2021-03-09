#include "addexpression.h"

template <typename T, typename Left, typename Right>
CAddExpression<T, Left, Right>::CAddExpression(
    std::shared_ptr<Left>  left,
    std::shared_ptr<Right> right)
    : left (left),
      right(right) {};


template <typename T, typename Left, typename Right>
T CAddExpression<T, Left, Right>::eval() const {
    return first->eval() + second->eval();
}