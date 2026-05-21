#include <iostream>
#include <vector>
#include "Account_Util.h"
#include "BankAccount.h"

// Displays BankAccount objects in a  vector of BankAccount objects 
void display(const std::vector<BankAccount*> &accounts) {
    std::cout << "\n=== BankAccounts ==========================================" << std::endl;
    for (const auto &acc: accounts) 
        std::cout << *acc << std::endl;
}

// Deposits supplied amount to each BankAccount object in the vector
void deposit(std::vector<BankAccount *> &accounts, double amount) {
    std::cout << "\n=== Depositing to BankAccounts =================================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc->deposit(amount)) 
            std::cout << "Deposited " << amount << " to " << *acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << *acc << std::endl;
    }
}

// Withdraw amount from each BankAccount object in the vector
void withdraw(std::vector<BankAccount *> &accounts, double amount) {
    std::cout << "\n=== Withdrawing from BankAccounts ==============================" <<std::endl;
    for (auto &acc:accounts)  {
        if (acc->withdraw(amount)) 
            std::cout << "Withdrew " << amount << " from " << *acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << *acc << std::endl;
    } 
}

// Deposits supplied amount to each BankAccount object in the vector
void deposit_op(std::vector<BankAccount *> &accounts, double amount) {
    std::cout << "\n=== += to BankAccounts =================================" << std::endl;
    for (auto &acc:accounts)  {
         *acc +=amount; 
         std::cout << "Deposited " << amount << " to " << *acc << std::endl;
    }
}

// Withdraw amount from each BankAccount object in the vector
void withdraw_op(std::vector<BankAccount *> &accounts, double amount) {
    std::cout << "\n=== -= from BankAccounts ==============================" <<std::endl;
    for (auto &acc:accounts)  {
        *acc -=amount; 
        std::cout << "Withdrew " << amount << " from " << *acc << std::endl;
    } 
}

void balance(std::vector<BankAccount *> &accounts)
{
    std::cout << "Balance of class &&&&&&&&&&&&&&&&&&&&&&&&& " << std::endl;
    for(auto acc : accounts)
    {
        std::cout << "Balance of '" << acc->get_name() << "' > " <<   acc->get_balance() << std::endl;
    }

}
