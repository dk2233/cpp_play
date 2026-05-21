#include "CheckAccount.h"
#include "BankAccount.h"
#include <ostream>


CheckAccount::CheckAccount(std::string name, double balance) : 
    BankAccount(name, balance)
{

}

bool CheckAccount::withdraw(double amount)
{
    
   return BankAccount::withdraw(amount + withdrawal_fee);

}


CheckAccount &CheckAccount::operator+=(double amount)
{

    CheckAccount::deposit(amount);

    return *this;

}

std::ostream &operator<<(std::ostream &os, const CheckAccount &account)
{
    os << "BankAccount " << account.name << " have balance " << account.balance;

    return os;
}


