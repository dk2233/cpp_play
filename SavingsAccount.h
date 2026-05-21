#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include "BankAccount.h"

// Savings Account is a type of BankAccount
//   adds an interest rate
// Withdraw - same as a regular account
// Deposit:
//      Amount supplied to deposit will be incremented by (amount * int_rate/100) 
//      and then the updated amount will be deposited
//

class SavingsAccount: public BankAccount {
    friend std::ostream &operator<<(std::ostream &os, const SavingsAccount &account);
private:
    static constexpr const char *def_name = "Unnamed Savings BankAccount";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
protected:
    double int_rate;
public:
    SavingsAccount(std::string name = def_name, double balance =def_balance, double int_rate = def_int_rate);    
    bool deposit(double amount);
    // Inherits the BankAccount::withdraw methods
};

#endif // _SAVINGS_ACCOUNT_H_
