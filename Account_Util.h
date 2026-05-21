#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_
#include <vector>
#include "BankAccount.h"

// Utility helper functions for BankAccount class

void display(const std::vector<BankAccount *> &accounts);
void deposit(std::vector<BankAccount *> &accounts, double amount);
void withdraw(std::vector<BankAccount *> &accounts, double amount);
void withdraw_op(std::vector<BankAccount *> &accounts, double amount) ;
void deposit_op(std::vector<BankAccount *> &accounts, double amount) ;
void balance(std::vector<BankAccount *> &accounts);
#endif
