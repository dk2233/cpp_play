#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_
#include <vector>
#include "BankAccount.h"
#include "CheckAccount.h"
#include "SavingsAccount.h"
#include "TrustAccount.h"

// Utility helper functions for BankAccount class

void display(const std::vector<BankAccount> &accounts);
void deposit(std::vector<BankAccount> &accounts, double amount);
void withdraw(std::vector<BankAccount> &accounts, double amount);

// Utility helper functions for Savings Account class

void display(const std::vector<SavingsAccount> &accounts);
void deposit(std::vector<SavingsAccount> &accounts, double amount);
void withdraw(std::vector<SavingsAccount> &accounts, double amount);

void display(const std::vector<CheckAccount> &accounts);
void deposit(std::vector<CheckAccount> &accounts, double amount);
void withdraw(std::vector<CheckAccount> &accounts, double amount);

void display(const std::vector<TrustAccount> &accounts);
void deposit(std::vector<TrustAccount> &accounts, double amount);
void withdraw(std::vector<TrustAccount> &accounts, double amount);

#endif
