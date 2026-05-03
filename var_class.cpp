#include "var_class.h"
#include <iostream>


var_class::var_class(int a, char c) : data_int{a} {
    for(int i=0 ; i < arr_size;  i++){
        data_array[i] = c;
    }
    std::cout << " created class var_class with int " << a << std::endl;
    
}

var_class::var_class()  {
    for(int i=0 ; i < arr_size;  i++){
        data_array[i] = ' ';
    }
    std::cout << " created class var_class " << std::endl;
    
}

void var_class::print_array() {
    for(char i : data_array)
    {
        std::cout << i << "," ; 
    }
    std::cout << std::endl;
}

var_class::~var_class() {
    std::cout << "class destruct called"<< std::endl;
}
/*
var_class::var_class(const var_class& base) {

    std::cout << "copy class called , address:" << &base <<  std::endl;

    data_int = base.data_int;

}*/
