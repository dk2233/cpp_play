#include "BankAccount.h"
#include "Account_Util.h"
#include "SavingsAccount.h"
#include "TrustAccount.h"
#include <vector>

void account_train(void)
{
    BankAccount *p = new TrustAccount("pointer type", 20000, 3.0);

    p->withdraw(100.0);

    std::cout << *p;

    
    SavingsAccount s {SavingsAccount("Grigor", 1234.0, 2.0)};
    
    BankAccount &account {s}; 

    account.withdraw(100.0);

    TrustAccount t ;
    BankAccount &ref  {t};

    ref.withdraw(200.0);

    std::vector<BankAccount> accounts = {
        BankAccount("Daniels account", 1000.0),
        BankAccount(),
        BankAccount("Maja")
    };

    display(accounts);


}

