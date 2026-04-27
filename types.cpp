#include <iostream>
#include <iterator>
#include "utils.h"
#include "templates.h"
#include "enum_train.h"
#include "var_class.h"

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

    Status_e enumStatus = Status_e::STATUS_INIT;

    var_class class_test(10, 'a') ;

    std::cout << "size of data types:" << std::endl;
    std::cout <<  "size of " << typeid(ff).name() << " " << sizeof(ff) << std::endl;
    std::cout <<  "size of " << typeid(dd).name() << " " << sizeof(dd) << std::endl;

    print_size_template(ff);
    print_size_template(a);
    print_size_template(c);
    print_size_template(enumStatus);
    print_size_template(class_test);


    marker_begin("TYPES END\n");
}
