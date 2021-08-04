#pragma once

#include <deque>
#include <stdexcept>
#include <condition_variable>
#include <mutex>


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
    int internalSize() const;

private:
    Container container;
    mutable std::mutex m;
    std::condition_variable cv;
};

template<typename ValueType, typename Container>
Stack<ValueType, Container>::Stack(std::initializer_list<ValueType> values)
  : container(values)
{
}

template<typename ValueType, typename Container>
ValueType Stack<ValueType, Container>::pop()
{
    std::unique_lock lock(m);
    cv.wait(lock, [&] { return !container.empty(); });
    const auto value = container.back();
    container.pop_back();
    return value;
}

template<typename ValueType, typename Container>
void Stack<ValueType, Container>::push(const ValueType& value)
{
    std::unique_lock lock(m);
    container.push_back(value);
    lock.unlock();
    cv.notify_all();
}

template<typename ValueType, typename Container>
int Stack<ValueType, Container>::size() const
{
    std::scoped_lock lock(m);
    // std::lock_guard lock(m); // in case of not supporting C++17

    // we use internalSize() instead of size() to avoid deadlock
    return internalSize();
}

template<typename ValueType, typename Container>
bool Stack<ValueType, Container>::isEmpty() const
{
    std::scoped_lock lock(m);
    // std::lock_guard lock(m); // in case of not supporting C++17
    return internalSize() == 0;
}

template<typename ValueType, typename Container>
int Stack<ValueType, Container>::internalSize() const
{
    return static_cast<int>(container.size());
}

} // namespace containers
