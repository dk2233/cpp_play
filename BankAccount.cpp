#include "BankAccount.h"

BankAccount::BankAccount(std::string name, double balance) 
    : name{name}, balance{balance} {
}

bool BankAccount::deposit(double amount) {
    if (amount < 0) 
        return false;
    else {
        balance += amount;
        return true;
    }
}

bool BankAccount::withdraw(double amount) {
    if (balance-amount >=0) {
        balance-=amount;
        return true;
    } else
        return false;
}

double BankAccount::get_balance() const {
    return balance;
}
std::string BankAccount::get_name() const {
    return name;
}


BankAccount &BankAccount::operator+=(double amount)
{
    deposit(amount);

    return *this;
}

BankAccount &BankAccount::operator-=(double amount)
{
    withdraw(amount);

    return *this;
}

CheckAccount::CheckAccount(std::string name, double balance) : 
    BankAccount(name, balance)
{

}

bool CheckAccount::withdraw(double amount)
{
    
   return BankAccount::withdraw(amount + withdrawal_fee);

}

void CheckAccount::print(std::ostream &os) const
{
    os << "[Checking Account :'" << name << "' have balance " << balance;

}


SavingsAccount::SavingsAccount(std::string name, double balance, double int_rate)
    : BankAccount {name, balance}, int_rate{int_rate} {
}

bool SavingsAccount::deposit(double amount) 
{
    amount += amount * (int_rate/100);
    return BankAccount::deposit(amount);
}

void SavingsAccount::print(std::ostream &os) const
{
    os << "[Savings Account: '" << name << "': " << balance << ", " << int_rate << "%]";
}


TrustAccount::TrustAccount(std::string name, double balance, double int_rate)    
     :SavingsAccount(name, balance, int_rate)
{
    withdraw_count = 0;
}


void TrustAccount::print(std::ostream &os) const
{
    os << "[Trust Account: '" << name << "': " << balance << ", " << int_rate << "% ]";
    os << " withdraw count " << withdraw_count;
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
