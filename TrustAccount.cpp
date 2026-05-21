#include "TrustAccount.h"
#include "SavingsAccount.h"

TrustAccount::TrustAccount(std::string name, double balance, double int_rate)    
     :SavingsAccount(name, balance, int_rate)
{
    withdraw_count = 0;
}


std::ostream &operator<<(std::ostream &os, const TrustAccount &account)
{
    os << "Trust Account " << account.name << ": " << account.balance << ", " << account.int_rate << "% ]";
    os << " withdraw count " << account.withdraw_count;

    return os;
}

bool TrustAccount::deposit(double amount)
{

    if (amount > deposit_pay_additional_price)
    {
        amount += additional_bounty; 
    }

    
    return (SavingsAccount::deposit(amount)); 

}

bool TrustAccount::withdraw(double amount)
{
    bool out {false};

    if ((withdraw_count < max_withdraw_no) && (amount < (balance * max_withdraw_percentage)))
    {
        out = SavingsAccount::withdraw(amount);
        if (out == true)
        {
            withdraw_count++;
        }
    }

    return out;
}
