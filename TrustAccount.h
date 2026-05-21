#ifndef TRUST_ACCOUNT_H
#define TRUST_ACCOUNT_H

#include "SavingsAccount.h"
class TrustAccount : public SavingsAccount
{
    
    friend std::ostream &operator<<(std::ostream &os, const TrustAccount &account);

private:
    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    static constexpr int max_withdraw_no {3};
    static constexpr double max_withdraw_percentage {0.2};
    static constexpr double deposit_pay_additional_price {5000.0};
    static constexpr double additional_bounty {50.0};
protected:
    int withdraw_count ;
    
public:
    TrustAccount(std::string name = def_name, double balance =def_balance, double int_rate = def_int_rate);    
    bool deposit(double amount);
    bool withdraw(double amount);

};



#endif
