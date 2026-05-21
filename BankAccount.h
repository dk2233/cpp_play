// Simple BankAccount 
#ifndef _BANKACCOUNT_H_
#define _BANKACCOUNT_H_
#include <ostream>
#include <string>
#include "IPrintable.h"

class BankAccount: public IPrintable {
private:   
    static constexpr const char *def_name = "Unnamed BankAccount";
    static constexpr double def_balance = 0.0;
protected:
    std::string name;
    double balance;
public:
    BankAccount(std::string name = def_name, double balance = def_balance);
    virtual bool deposit(double amount);
    virtual bool withdraw(double amount);
    double get_balance() const;
    std::string get_name() const;
    void print(std::ostream &os) const  = 0;
    virtual BankAccount &operator+=(double amount);
    virtual BankAccount &operator-=(double amount);
    virtual ~BankAccount() = default;
};


class CheckAccount : public BankAccount
{
    private:
        static constexpr double withdrawal_fee {1.5} ;
        static constexpr const char * def_name = "Unnamed Checking Account";
        static constexpr const double def_balance {0.0};

    public:

        CheckAccount(std::string name = def_name, double balance = def_balance);

        bool withdraw(double amount) override;

        virtual void print(std::ostream &os) const override;
};

class SavingsAccount: public BankAccount {
private:
    static constexpr const char *def_name = "Unnamed Savings BankAccount";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
protected:
    double int_rate;
public:
    SavingsAccount(std::string name = def_name, double balance =def_balance, double int_rate = def_int_rate);    
    bool deposit(double amount) override;

    virtual void print(std::ostream &os) const override;
};


class TrustAccount : public SavingsAccount
{
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
    bool deposit(double amount) override;
    bool withdraw(double amount) override;
    virtual void print(std::ostream &os) const override;

};



#endif
