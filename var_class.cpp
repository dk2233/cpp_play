#include "var_class.h"
#include <iostream>

void var_class_heap(var_class &vars) ;

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
void var_class_heap(var_class &vars) {
    //run script trace_heap_use
    var_class *vars_heap1 = new var_class();

    var_class *vars_heap_copy = new var_class(vars); 

    delete vars_heap1;
    delete vars_heap_copy;
}

void var_class_test() 
{
    var_class vars(10, 'a');
    var_class vars2(39, 'l');
    var_class vars3;
    //run trace_copy_const_default
    var_class vars4(vars);
    
    vars.print_array();
    vars2.print_array();
    vars3.print_array();
    vars4.print_array();

    var_class_heap(vars);
    
    printf("size of class %ld\n\n", sizeof(var_class));
}
