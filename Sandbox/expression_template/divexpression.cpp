#include "divexpression.h"

template <typename T, typename Left, typename Right>
CDivExpression<T, Left, Right>::CDivExpression(
    std::shared_ptr<Left>  left,
    std::shared_ptr<Right> right)
    : left (left),
      right(right) {};


template <typename T, typename Left, typename Right>
T CDivExpression<T, Left, Right>::eval() const {
    return first->eval() / second->eval();
}