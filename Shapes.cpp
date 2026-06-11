#include "IPrintable.h"
#include <iomanip>
#include <ostream>
#include "Shapes.h"
#include <iostream>

double Square::calc_area() const
{
    return a*a;

}

void Square::print(std::ostream &os) const 
{
    os << "Square with " << a << " size, area field is " << calc_area() << std::endl;

}
bool Square::operator<(const Shape &s)
{
    const Square * sq = dynamic_cast<const Square *>(&s);
    std::cout << "this " << a  
        << " <  rhs " << sq->a  << std::endl; 
    return calc_area() < sq->calc_area();
}

double Rectangle::calc_area() const
{
    return a*b;

}

void Rectangle::print(std::ostream &os) const 
{
    os << "Rectangle with " << a << " and " << b << " size,  area field is " << calc_area() << std::endl;

}

bool Rectangle::operator<(const Shape &r)
{
    const Rectangle *rec = dynamic_cast<const Rectangle *>(&r);
    std::cout << "this " << a << " , " << b 
        << " <  rhs " << rec->a << rec->b << std::endl; 
    return calc_area() < rec->calc_area();
}

double Rhombus::calc_area() const
{
    return a*h;
}

void Rhombus::print(std::ostream &os) const
{
    os << "Rhombus with base " << a << " ,height " << h << ", area is " << calc_area() << std::endl;
}

bool Rhombus::operator<(const Shape &s)
{
    const Rhombus *rr = dynamic_cast<const Rhombus *>(&s);

    if (rr != nullptr) 
    {
        std::cout << "this " << a << " , " << h 
        << " <  rhs " << rr->a << rr->h << std::endl;
    }
    else 
    {
        /* this shall be always check */
    }
    
    return calc_area() < rr->calc_area();
}

void display_shape_vec(const std::vector<Shape> &shapes)
{
    std::cout << std::setw(50) << std::setfill('*') << "" << std::endl;
    std::cout << " showing vector with Shapes : " << std::endl;
    for(const Shape &s : shapes)
    {
        std::cout << s << std::endl;
    }
    std::cout << std::setw(50) << std::setfill('*') << "" << std::endl;
}

void display_shape_vec(const std::vector<std::unique_ptr<Shape>> &shapes)
{
    std::cout << std::setw(50) << std::setfill('*') << "" << std::endl;
    std::cout << " showing vector with Shapes : " << std::endl;
    for(auto &s : shapes)
    {
        std::cout << *s << std::endl;
    }
    std::cout << std::setw(50) << std::setfill('*') << "" << std::endl;
}
