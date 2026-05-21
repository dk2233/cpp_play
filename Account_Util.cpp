#include <iostream>
#include "Account_Util.h"
#include "BankAccount.h"
#include "CheckAccount.h"
#include "TrustAccount.h"

// Displays BankAccount objects in a  vector of BankAccount objects 
void display(const std::vector<BankAccount> &accounts) {
    std::cout << "\n=== BankAccounts ==========================================" << std::endl;
    for (const auto &acc: accounts) 
        std::cout << acc << std::endl;
}

// Deposits supplied amount to each BankAccount object in the vector
void deposit(std::vector<BankAccount> &accounts, double amount) {
    std::cout << "\n=== Depositing to BankAccounts =================================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc.deposit(amount)) 
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
}

// Withdraw amount from each BankAccount object in the vector
void withdraw(std::vector<BankAccount> &accounts, double amount) {
    std::cout << "\n=== Withdrawing from BankAccounts ==============================" <<std::endl;
    for (auto &acc:accounts)  {
        if (acc.withdraw(amount)) 
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    } 
}


// Helper functions for Savings Account class

// Displays Savings Account objects in a  vector of Savings Account objects 
void display(const std::vector<SavingsAccount> &accounts) {
    std::cout << "\n=== Savings Accounts ====================================" << std::endl;
    for (const auto &acc: accounts) 
        std::cout << acc << std::endl;
}

// Displays Savings Account objects in a  vector of Savings Account objects 
void display(const std::vector<CheckAccount> &accounts) {
    std::cout << "\n=== Checking Accounts ====================================" << std::endl;
    for (const auto &acc: accounts) 
        std::cout << acc << std::endl;
}

void display(const std::vector<TrustAccount> &accounts) {
    std::cout << "\n=== Trust Accounts ====================================" << std::endl;
    for (const auto &acc: accounts) 
        std::cout << acc << std::endl;
}

// Deposits supplied amount to each Savings Account object in the vector
void deposit(std::vector<SavingsAccount> &accounts, double amount) {
    std::cout << "\n=== Depositing to Savings Accounts ==========================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc.deposit(amount)) 
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
}
// Deposits supplied amount to each Checking Account object in the vector
void deposit(std::vector<CheckAccount> &accounts, double amount) {
    std::cout << "\n=== Depositing to Checking Accounts ==========================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc.deposit(amount)) 
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
}
// Deposits supplied amount to each Trust Account object in the vector
void deposit(std::vector<TrustAccount> &accounts, double amount) {
    std::cout << "\n=== Depositing to Trust Accounts ==========================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc.deposit(amount)) 
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
}

// Withdraw supplied amount from each Savings Account object in the vector
void withdraw(std::vector<SavingsAccount> &accounts, double amount) {
    std::cout << "\n=== Withdrawing from Savings Accounts ======================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc.withdraw(amount)) 
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    } 
}
//
// Withdraw supplied amount from each CheckAccount Account object in the vector
void withdraw(std::vector<CheckAccount> &accounts, double amount) {
    std::cout << "\n=== Withdrawing from Checking Accounts ======================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc.withdraw(amount)) 
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    } 
}

// Withdraw supplied amount from each Trust Account object in the vector
void withdraw(std::vector<TrustAccount> &accounts, double amount) {
    std::cout << "\n=== Withdrawing from Trust Accounts ======================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc.withdraw(amount)) 
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    } 
}

