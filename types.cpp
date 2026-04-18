#include <iostream>
#include "utils.h"


void types_test()
{
    //std::cout << "-------------------- TYPES" << std::endl;
    marker_begin("TYPES");
    auto a = 2;
    int b = 0;
    const volatile int c_c = 20;
    constexpr int c_const = 0xaa;

    char c = 0x64;

    std::cout << "znak " << int(c) << " -> " << c << std::endl;
    std::cout << "znak +1 " << int(c+1) << " -> " << c+1 << std::endl;

    std::cout << "constexpr " << c_const << std::endl;

    a = c_const + a ; 

    b = c_c + b ; 

    std::cout << a << std::endl;

    bool cond = a < c;

    std::cout << "condition a (" << a << ")< c (" << int(c) << ") -> this condition has value = " << cond << std::endl;
    cond = b < c;
    std::cout << "condition b (" << b << ")< c (" << int(c) << ") -> this condition has value = " << cond << std::endl;

    cond = true;

    std::cout << "simple true has value: " << cond << std::endl;

    float ff = 3.4f;
    double dd = 4.567; 

    std::cout << "float example " << ff << " and double " << dd << std::endl;

    marker_begin("TYPES END\n");
}
