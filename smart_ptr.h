#ifndef SMART_PTR_H
#define SMART_PTR_H
/*
 *
 * this file is a sandbox to play with 
 * smart pointers
 */

#include <iostream>
#include <memory>
#include <ostream>
class A; class B;

class I_AB 
{
    friend std::ostream &operator<<(std::ostream &os, I_AB &ab); 
    public:
        virtual void set_ptr(const std::weak_ptr<A> &pA) = 0;
        virtual void set_ptr(const std::shared_ptr<B> &pB) = 0;
        virtual ~I_AB() = default;
        virtual void print(std::ostream &os) =0;
};

class A: public I_AB 
{
    private:
        std::shared_ptr<B> ptr_B ;
    public:
        A(std::shared_ptr<B> pB = nullptr): ptr_B{pB}
        {
            std::cout << "constructed A with " << pB << std::endl;
        }

        ~A() {
            std::cout << "A destruct " << std::endl;
        }

        void set_ptr(const std::shared_ptr<B> &pB) override {
           ptr_B = pB; 
        }
        void set_ptr(const std::weak_ptr<A> & /*&pA*/) override {  };

        void print(std::ostream &os) override;
};

class B: public I_AB 
{
    private:
        //std::shared_ptr<A> ptr_A ; //this blocks A from being delete        
        std::weak_ptr<A> ptr_A; 
        
    public:
        B(std::shared_ptr<A> pA = nullptr): ptr_A{pA}
        //B(std::weak_ptr<A> pA = nullptr): ptr_A{pA}
        {
            std::cout << "constructed B with " << pA << std::endl;
        }


        ~B() {
            std::cout << "B destruct " << std::endl;
        }

        void set_ptr(const std::weak_ptr<A> &pA) override {
           ptr_A = pA; 
        }
        void set_ptr(const std::shared_ptr<B> &/*pB*/) override {}
        void print(std::ostream &os) override;
};

void smart_ptr();

#endif
