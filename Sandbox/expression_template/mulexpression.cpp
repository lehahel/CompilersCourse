#include "mulexpression.h"

template <typename T, typename Left, typename Right>
CMulExpression<T, Left, Right>::CMulExpression(
    std::shared_ptr<Left>  left,
    std::shared_ptr<Right> right)
    : left (left),
      right(right) {};


template <typename T, typename Left, typename Right>
T CMulExpression<T, Left, Right>::eval() const {
    return first->eval() * second->eval();
}