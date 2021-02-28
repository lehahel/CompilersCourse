template <typename T>
class CExpression {
public:
    virtual T eval() const = 0;
};