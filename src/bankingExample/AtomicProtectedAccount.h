#pragma once

#include <atomic>

class AtomicProtectedAccount
{
public:
    int balance() const;

    void deposit(int payment);
    void withdraw(int money);

private:
    std::atomic<int> money = 0;
};
