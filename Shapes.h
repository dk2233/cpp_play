#ifndef SHAPES_H
#define SHAPES_H
#include "IPrintable.h"
#include <ostream>

class Shapes : public IPrintable
{

    private:

    public:
        virtual double calc_area() const = 0;

        virtual void print(std::ostream &os) const = 0;
        
        virtual ~Shapes() = default;

};

class Square : public Shapes 
{
    private:
        double a;
    public:
        virtual double calc_area() const;

        virtual void print(std::ostream &os) const ;

        virtual ~Square() = default;

        Square(double a = 0.0); 
};

class Rectangle : public Shapes 
{
    private:
        double a, b;
    public:
        virtual double calc_area() const;

        virtual void print(std::ostream &os) const ;

        virtual ~Rectangle() = default;

        Rectangle(double a = 0.0, double b = 0.0); 

};

class Rhombus: public Shapes
{
    private: 
        double a, h;
    public:
        virtual double calc_area() const;

        virtual void print(std::ostream &os) const ;

        virtual ~Rhombus() = default;

        Rhombus(double a = 1.0, double h = 1.0): a{a}, h{h} 
        {
        };

};
#endif
