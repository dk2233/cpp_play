#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "BankAccount.h"
#include <ostream>


class CheckAccount : public BankAccount
{
    private:
        static constexpr double withdrawal_fee {1.5} ;
        static constexpr const char * def_name = "Unnamed Checking Account";
        static constexpr const double def_balance {0.0};

    public:
        friend std::ostream &operator<<(std::ostream &os, const CheckAccount &account); 

        CheckAccount(std::string name = def_name, double balance = def_balance);

        bool withdraw(double amount);

        CheckAccount &operator+=(const double amount);
};


#endif
