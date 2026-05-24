
#include "IPrintable.h"
#include <ostream>
#include "Shapes.h"

double Square::calc_area() const
{
    return a*a;

}

void Square::print(std::ostream &os) const 
{
    os << "Square with " << a << " size, area field is " << calc_area() << std::endl;

}

Square::Square(double a) : a{a}
{

}

Rectangle::Rectangle(double a, double b ) : a{a}, b{b}
{

}


double Rectangle::calc_area() const
{
    return a*b;

}

void Rectangle::print(std::ostream &os) const 
{
    os << "Rectangle with " << a << " and " << b << " size,  area field is " << calc_area() << std::endl;

}

double Rhombus::calc_area() const
{
    return a*h;
}

void Rhombus::print(std::ostream &os) const
{
    os << "Rhombus with base " << a << " ,height " << h << ", area is " << calc_area() << std::endl;
}

