#include "BankAccount.h"
#include "Account_Util.h"
#include <ios>
#include <memory>
#include <vector>
#include <iostream>
#include "Shapes.h"
#include "utils.h"

void account_train(void)
{

    marker_begin(" Class accout TEST ");
    BankAccount *p = new TrustAccount("pointer type", 20000, 3.0);

    p->withdraw(100.0);

    std::cout << *p << std::endl ;
    *p += 200.0;

    std::cout << *p << std:: endl;

    
    SavingsAccount s {SavingsAccount("Grigor", 1234.0, 2.0)};
    
    BankAccount &account {s}; 

    std::cout << account << std::endl;
    account.withdraw(100.0);

    std::cout << account << std::endl;
    account += 1000.0;

    std::cout << account << std::endl;

    s.deposit(1000.0);
    std::cout << s << std::endl;

    TrustAccount t ;
    BankAccount &ref  {t};

    ref.withdraw(200.0);

    std::vector<BankAccount *> accounts = {
        new CheckAccount("Daniels check account", 1000.0),
        new CheckAccount("Erik check account", 10000.0),
        new SavingsAccount(),
        new SavingsAccount("Trump's savings",1233, 1.5),
        new TrustAccount("Maja")
    };

    display(accounts);
    deposit(accounts, 20000.0);
    withdraw(accounts, 300.0);
    display(accounts);

    deposit_op(accounts, 100.0);

    display(accounts);

    for(int i = 0; i < 4 ; i++) 
    {
        withdraw(accounts, 300.0);
        display(accounts);
    }

    withdraw_op(accounts, 234);
    display(accounts);

    balance(accounts);
    for(auto p : accounts)
    {
        delete p;
    }

    marker_begin(" Class accout END ");
}

void shapes_test()
{
    marker_begin(" Class shapes TEST ");
    Shape * s1 = new Square(2.0);

    std::cout << *s1 << std::endl;

    delete s1;
    
    s1 = new Rectangle(2.0, 3.0);
    std::cout << *s1 << std::endl;

    delete s1;

    //using unique_ptr with new keyword
    std::unique_ptr<Shape> s3 {new Square(3.5)};
    std::cout << "smart pointer in " << s3 << " points to " << s3.get() << ", " << *s3 <<std::endl;
    std::cout << *s3 << std::endl;
    s3.reset();

    s3 = std::make_unique<Square>(Square(2.5));
    std::cout << *s3 << std::endl;
    
    //using unique_ptr with new keyword 
    std::unique_ptr<Shape> s4 = std::make_unique<Rectangle>(Rectangle(2.0, 7.8));

    std::cout << *s4 ;

    std::vector<std::unique_ptr<Shape>> ptr = {};
    //cannot call function with unique_ptr
    //but we can move ownership
    ptr.push_back(std::move(s4));

    std::cout << *(ptr.at(0));
    std::cout << ptr.at(0)->calc_area() << std::endl ;

    std::shared_ptr<Shape> s2 = std::make_shared<Rhombus>(3.4);

    std::cout << *s2 ;

    ptr.push_back(std::make_unique<Square>(Square(3.5)));
    ptr.push_back(std::make_unique<Rhombus>(Rhombus(3.5, 4.5)));

    display_shape_vec(ptr);

    std::cout << " Sorting .... " << std::endl;

    std::sort(ptr.begin(), ptr.end(), [](const std::unique_ptr<Shape> &p1, const std::unique_ptr<Shape> &p2) {
            return p1->calc_area() < p2->calc_area(); });


    display_shape_vec(ptr);
    
    std::boolalpha;

    /*this wont work - it is because under the hood 
    * it will compare squar< rectangle - and this will not be clear
    * dynamic_cast will not know how to cast rectangle to Square
    *
    * (ptr.at(0)) < *(ptr.at(1));
    *
    * here is nice lesson - do not use operator overloading in case of class hierarchy
    * also DRY is broken
    */
    marker_begin(" Class shapes END ");
}

