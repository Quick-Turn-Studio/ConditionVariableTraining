#pragma once

#include <deque>
#include <stdexcept>

namespace containers
{

template<typename ValueType, class Container = std::deque<ValueType>>
class Stack
{
public:
    Stack() = default;
    Stack(std::initializer_list<ValueType> values);

    /**
     * Remove last added element and returns it
     * Throws an std::out_of_range exception if stack is empty
     * @return popped element
     */
    ValueType pop();
    void push(const ValueType& value);

    bool isEmpty() const;
    int size() const;

private:
    Container container;
};

template<typename ValueType, typename Container>
Stack<ValueType, Container>::Stack(std::initializer_list<ValueType> values)
  : container(values)
{
}

template<typename ValueType, typename Container>
ValueType Stack<ValueType, Container>::pop()
{
    if (container.empty()) {
        throw std::out_of_range("Stack is empty");
    }
    const auto value = container.back();
    container.pop_back();
    return value;
}

template<typename ValueType, typename Container>
void Stack<ValueType, Container>::push(const ValueType& value)
{
    container.push_back(value);
}

template<typename ValueType, typename Container>
int Stack<ValueType, Container>::size() const
{
    return static_cast<int>(container.size());
}

template<typename ValueType, typename Container>
bool Stack<ValueType, Container>::isEmpty() const
{
    return size() == 0;
}

} // namespace containers
