#include "Account.h"
#include "AtomicProtectedAccount.h"
#include "BlockingAccount.h"
#include "MutexProtectedAccount.h"
#include "ReadyBlockingAccount.h"

#include <iostream>
#include <stdexcept>
#include <thread>

using AccountType = Account;
// using AccountType = MutexProtectedAccount;

void wait(int seconds)
{
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void depositMoneyWorker(AccountType& account)
{
    account.deposit(200);
    std::cout << "Deposited 200" << std::endl;

    wait(1);
    account.deposit(100);
    std::cout << "Deposited 100" << std::endl;

    wait(1);
    account.deposit(200);
    std::cout << "Deposited 200" << std::endl;

    wait(1);
    account.deposit(300);
    std::cout << "Deposited 300" << std::endl;
}

void withdrawMoneyWorker(AccountType& account)
{
    wait(1);
    account.withdraw(500);
    std::cout << "Withdrawn 500" << std::endl;
}

void safeWithdrawMoneyWorker(AccountType& account)
{
    wait(1);
    try {
        account.withdraw(500);
        std::cout << "Withdrawn 500" << std::endl;
    }
    catch (const std::runtime_error& exception) {
        std::cout << exception.what() << std::endl;
    }
}

int main()
{
    AccountType account;
    auto parentThread = std::thread(depositMoneyWorker, std::ref(account));
    //    auto studentThread = std::thread(withdrawMoneyWorker, std::ref(account));
    auto studentThread = std::thread(safeWithdrawMoneyWorker, std::ref(account));

    parentThread.join();
    studentThread.join();

    return 0;
}