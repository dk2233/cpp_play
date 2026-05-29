#include "utils.h"
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <vector>


void check_exception() {

    marker_begin("EXCEPTION BEGIN");
    std::vector<int> array1 = {0, 1, 2, 3};


    try {
    std::cout << array1.at(0) << ", " << array1.at(4) << std::endl ;
    }
    catch(const std::out_of_range &e)
    {
        std::cerr << "error you tried to read from non existing index" << std::endl;
    }

    int a {10}, b {2};

    try{
        if (b == 0)
            throw 0;
        std::cout << a / b << std::endl;
    }
    catch(int &e)
    {
        std::cerr << "div by zero " << e << std::endl;

    }
    
    marker_begin("EXCEPTION END");
}
 



