#include "templates.h"
#include "types.h"
#include <iostream>

void arrays_tests()
{

    int array_int [10] {10,9,-90};
    float array_f [5] {2.222, 4.567};

    std::cout << array_int[0] << std::endl;
    
    show_container(array_int);

    show_container(array_f);




}
