/*
 *
 * this file is a sandbox to play with 
 * smart pointers
 */
#include "smart_ptr.h"
#include "utils.h"
#include <concepts>
#include <iostream>
#include <memory>
#include <ostream>
#include <utility>
#include "var_class.h"

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

template <typename T>
concept CheckDisplayOp = requires(std::ostream &os, const T &tt)
{
    {os << tt} -> std::same_as<std::ostream &>;
};

template  <typename Ptr>
requires CheckDisplayOp<decltype(*std::declval<Ptr>())>
void func_unique(const Ptr &ptr)
{
    std::cout << *ptr << std::endl;
};

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


    std::unique_ptr<int> ptr_un = std::make_unique<int>(10);

    //do not have to use std::move - function takes arg as reference
    func_unique(ptr_un);

    std::unique_ptr<var_class> ptr_var_un = std::make_unique<var_class>(10, 34);

    //this wont compile
    //func_unique(ptr_var_un);

    marker_begin("SMART POINTER END");
}
