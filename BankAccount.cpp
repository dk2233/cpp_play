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

std::ostream &operator<<(std::ostream &os, const BankAccount &account) {
    os << "[BankAccount: " << account.name << ": " << account.balance << "]";
    return os;
}
