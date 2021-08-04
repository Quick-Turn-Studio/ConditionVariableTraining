#include "AtomicProtectedAccount.h"

#include <stdexcept>

int AtomicProtectedAccount::balance() const
{
    return money;
}

void AtomicProtectedAccount::deposit(int payment)
{
    money += payment;
}

void AtomicProtectedAccount::withdraw(int amount)
{
    if (amount > money) {
        throw std::runtime_error("not enough money");
    }
    money -= amount;
}
