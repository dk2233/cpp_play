// Simple BankAccount 
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <string>

class BankAccount {
    friend std::ostream &operator<<(std::ostream &os, const BankAccount &account);
private:   
    static constexpr const char *def_name = "Unnamed BankAccount";
    static constexpr double def_balance = 0.0;
protected:
    std::string name;
    double balance;
public:
    BankAccount(std::string name = def_name, double balance = def_balance);
    // BankAccount(std::string name = "Unamed Account", double balance = 0.0);
    bool deposit(double amount);
    bool withdraw(double amount);
    double get_balance() const;
};
#endif
