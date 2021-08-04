#pragma once

#include <mutex>

class BlockingAccount
{
public:
    int balance() const;

    void deposit(int payment);
    void withdraw(int money);

private:
    mutable std::mutex moneyMutex; // we need mutable to change
    int money = 0;                 // mutex in const methods
};
