#pragma once

class Account
{
public:
    int balance() const;

    void deposit(int payment);
    void withdraw(int money);

private:
    int money = 0;
};
