#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(std::string name, double balance, double int_rate)
    : BankAccount {name, balance}, int_rate{int_rate} {
}

bool SavingsAccount::deposit(double amount) {
    amount += amount * (int_rate/100);
    return BankAccount::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const SavingsAccount &account) {
    os << "[SavingsAccount: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
}

