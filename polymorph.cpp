#include "BankAccount.h"
#include "Account_Util.h"
#include <vector>
#include <iostream>

void account_train(void)
{
    BankAccount *p = new TrustAccount("pointer type", 20000, 3.0);

    p->withdraw(100.0);

    std::cout << *p << std::endl ;
    *p += 200.0;

    std::cout << *p << std:: endl;

    
    SavingsAccount s {SavingsAccount("Grigor", 1234.0, 2.0)};
    
    BankAccount &account {s}; 

    std::cout << account << std::endl;
    account.withdraw(100.0);

    std::cout << account << std::endl;
    account += 1000.0;

    std::cout << account << std::endl;

    s.deposit(1000.0);
    std::cout << s << std::endl;

    TrustAccount t ;
    BankAccount &ref  {t};

    ref.withdraw(200.0);

    std::vector<BankAccount *> accounts = {
        new CheckAccount("Daniels check account", 1000.0),
        new CheckAccount("Erik check account", 10000.0),
        new SavingsAccount(),
        new SavingsAccount("Trump's savings",1233, 1.5),
        new TrustAccount("Maja")
    };

    display(accounts);
    deposit(accounts, 20000.0);
    withdraw(accounts, 300.0);
    display(accounts);

    deposit_op(accounts, 100.0);

    display(accounts);

    for(int i = 0; i < 4 ; i++) 
    {
        withdraw(accounts, 300.0);
        display(accounts);
    }

    withdraw_op(accounts, 234);
    display(accounts);

    balance(accounts);
    for(auto p : accounts)
    {
        delete p;
    }

}

