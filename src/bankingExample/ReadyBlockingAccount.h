#pragma once

#include <mutex>
#include <condition_variable>

class ReadyBlockingAccount
{
public:
    int balance() const;

    void deposit(int payment);
    void withdraw(int money);

private:
    mutable std::mutex moneyMutex;
    std::condition_variable moneyCv;
    int money = 0;
};
