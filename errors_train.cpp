#include <iostream>
#include <ostream>
#include <stdexcept>
#include <vector>


void check_exception() {

    std::vector<int> array1 = {0, 1, 2, 3};


    try {
    std::cout << array1.at(0) << ", " << array1.at(4) << std::endl ;
    }
    catch(const std::out_of_range &e)
    {
        std::cerr << "error you try to read from non existing index" << std::endl;
    }
}
 



