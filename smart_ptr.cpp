/*
 *
 * this file is a sandbox to play with 
 * smart pointers
 */
#include "smart_ptr.h"
#include "utils.h"
#include <iostream>
#include <memory>
#include <ostream>

std::ostream &operator<<(std::ostream &os, I_AB &ab) 
{

    ab.print(os);
    return os;
}

void A::print(std::ostream &os)
{
    os << "\nClass A, with ptr " << ptr_B << std::endl; 
    os << "\tnumber of usage " << ptr_B.use_count() << std::endl;

}
void B::print(std::ostream &os)
{
    if (auto shared_A = ptr_A.lock())
        os << "\nClass B, with ptr locked from weak " << shared_A << std::endl; 
    os << "\tnumber of usage " << ptr_A.use_count() << std::endl;

}

void smart_ptr()
{
    marker_begin("SMART POINTER BEGIN");


    std::shared_ptr<A> a1 = std::make_shared<A>();
    std::shared_ptr<B> b1 = std::make_shared<B>(a1);
    std::cout << "B adress " << b1 << std::endl;
    //std::cout << b1 << std::endl;
    std::cout << *a1;
    std::cout << *b1;
    a1->set_ptr(b1);
    std::cout << *a1;
    std::cout << *b1;
            //std::move(std::make_shared<B>(*b1)));
    std::cout << *a1;
    std::shared_ptr<A> a2  {a1};
    std::cout << *a1;
    std::cout << "usage of a1 " << a1.use_count() << std::endl;
    std::cout << b1.use_count() << std::endl;

    //a1.s
    marker_begin("SMART POINTER END");
}
