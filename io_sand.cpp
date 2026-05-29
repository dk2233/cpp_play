


#include "utils.h"
#include <ios>
#include <iostream>
#include <iomanip>
void io_sandbox()
{

    marker_begin("Input Output Begin");
    double d1 (1.23456789);

    std::cout<< std::setw(20) << std::setfill('*') <<  "Test" << std::endl;
    std::cout << std::defaultfloat;
    std::cout << " Double number with default prec "<< d1 << std::endl;
    std::cout << std::setprecision(10) ;
    std::cout << " Double number with 10 prec "<< d1 << std::endl;
    std::cout << std::setprecision(2) ;
    std::cout << " Double number with 10 prec "<< d1 << std::endl;

    marker_begin("Input Output END");
}
