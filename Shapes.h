#ifndef SHAPES_H
#define SHAPES_H
#include "IPrintable.h"
#include <memory>
#include <ostream>
#include <iostream>

class Shape : public IPrintable
{

    private:

    public:
        virtual double calc_area() const = 0;

        virtual void print(std::ostream &os) const = 0;
        
        virtual ~Shape() = default;

        /* interface should not have any overload operator defined - this is more for specific class
         *
         * all of them have to be defined in the same way - so we have to use 
         *  Shape argument always and than dynamic_cast argument 
         *
         * if we try to compare square < rectangle - rectangle will not be dynamic cast to square
         *
         */
        virtual bool operator<(const Shape &rhs) = 0;
        
};

class Square : public Shape 
{
    private:
        double a;
    public:
        virtual double calc_area() const override;

        virtual void print(std::ostream &os) const override;

        virtual ~Square() = default;

        Square(double a = 0.0) : a{a}{}; 

        bool operator<(const Shape &rhs) override;
};

class Rectangle : public Shape 
{
    private:
        double a, b;
    public:
        virtual double calc_area() const override;

        virtual void print(std::ostream &os) const override;

        virtual ~Rectangle() = default;

        Rectangle(double a = 0.0, double b = 0.0): a{a}, b{b}{}; 

        bool operator<(const Shape &rhs) override;

};

class Rhombus: public Shape
{
    private: 
        double a, h;
    public:
        virtual double calc_area() const override;

        virtual void print(std::ostream &os) const override ;

        virtual ~Rhombus() = default;

        Rhombus(double a = 1.0, double h = 1.0): a{a}, h{h} 
        {
        };


        bool operator<(const Shape &rhs) override;

};


void display_shape_vec(const std::vector<Shape> &shapes);

void display_shape_vec(const std::vector<std::unique_ptr<Shape>> &shapes);

#endif
