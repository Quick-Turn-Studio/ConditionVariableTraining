#include "MutexProtectedAccount.h"

int MutexProtectedAccount::balance() const
{
    std::lock_guard<std::mutex> lock(moneyMutex); // until C++17 we use
    return money;                                 // std::lock_guard
}

void MutexProtectedAccount::deposit(int payment)
{
    std::lock_guard lock(moneyMutex); // since C++17 we have type deduction
    money += payment;                 // so we can skip template type
}

void MutexProtectedAccount::withdraw(int amount)
{
    std::scoped_lock lock(moneyMutex);  // since C++17 we have use std::scoped_lock
    if (amount > money) {
        throw std::runtime_error("not enough money");
    }
    money -= amount;
}

