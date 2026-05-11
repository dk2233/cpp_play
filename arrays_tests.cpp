#include "templates.h"
#include "types.h"
#include <array>
#include <cstddef>
#include <iostream>
#include <vector>
#include <span>

void set_array(int a[], size_t s)
{
    a[0] = 100;
    for(int i = 0; i < s; i++)
    {
        std::cout << a[i] << ", " ;
    }
    std::cout << std::endl;
}


void arrays_tests()
{

    int array_int [10] {10,9,-90};
    float array_f [5] {2.222, 4.567};

    /*check in debugger how it is realized in asembler
     */
    array_int[1] = 23;
    std::cout << array_int[0] << std::endl;
    
    show_container(array_int);

    show_container(array_f);

    //check this behaviour with uncomment
    //array_int[11] = 0;

    std::vector<int> vec_int (5);

    vec_int.at(0) = 100;
    //this will not check if such element exists and may not even crash
    //vec_int[10] = 0;
    /*this is safer but has an overhead
    
      and will crash the program - so it is safe
    vec_int.at(10) = 0;
    */
    show_container<std::vector<int>>(vec_int);

    std::vector<char> vec_char (200, 0x64);

    show_container(vec_char);

    /*check in asembler difference of this two approach
     */
    vec_char[0] = 0x65;
    vec_char.at(1) = 0x20;
    vec_char.push_back(0xa0);
    show_container(vec_char);


    std::array<int, 10> arr_cpp1 {0};
    arr_cpp1.at(0) = 9; 

    show_container(arr_cpp1);


    /*
     * much more efficient
     */
    std::span<int> span_int1 = arr_cpp1;


    show_container(span_int1);
    
    set_array(array_int, 10 );

}
