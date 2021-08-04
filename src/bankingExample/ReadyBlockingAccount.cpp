#include "ReadyBlockingAccount.h"

int ReadyBlockingAccount::balance() const
{
    std::scoped_lock lock(moneyMutex);
    return money;
}

void ReadyBlockingAccount::deposit(int payment)
{
    std::unique_lock lock(moneyMutex);
    money += payment;
    lock.unlock();
//    moneyCv.notify_one();
    moneyCv.notify_all();
}

void ReadyBlockingAccount::withdraw(int amount)
{
    std::unique_lock lock(moneyMutex);
    moneyCv.wait(lock, [&] { return amount <= money; });
//    }
    money -= amount;
}