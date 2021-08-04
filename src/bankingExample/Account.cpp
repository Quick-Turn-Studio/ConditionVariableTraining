#include "Account.h"

#include <stdexcept>

int Account::balance() const
{
    return money;
}

void Account::deposit(int payment)
{
    money += payment;
}

void Account::withdraw(int amount)
{
    if (amount > money) {
        throw std::runtime_error("not enough money");
    }
    money -= amount;
}
