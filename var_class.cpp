#include "var_class.h"
#include "templates.h"
#include <algorithm>
#include <iostream>
#include <string>

void var_class_heap(var_class &vars) ;
void var_class_mv_test(var_class &vars);

std::list<std::string> *  var_class::get_list() const {
return list_words;
}

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
    std::cout << "class destruct called for class " << typeid(*this).name()<< std::endl;
}

var_class_mv::var_class_mv(const var_class_mv& base) {

    std::cout << "copy class called , address:" << &base <<  std::endl;

    data_int = base.data_int;

}

var_class_mv::var_class_mv(const var_class& base):var_class(base) {
    std::cout << "copy class called from base  , address:" << &base <<  std::endl;

    list_words = new std::list<std::string>(*(base.get_list()));

    std::cout << "list words of base " << std::endl;
    show_container(*(base.get_list()));
    std::cout << "list words of new class " << std::endl;

    show_container(*(get_list()));
}

var_class_mv::var_class_mv(int a, char c ) : var_class(a, c)
{

}
void var_class::add_word(const std::string& word)
{

    list_words->push_back(word);

}

var_class_mv::var_class_mv(var_class_mv&& base) noexcept :
var_class(std::move(base))
{
    list_words = base.list_words;
    base.list_words = nullptr;
    std::cout << "move constructor " << std::endl;

}

void var_class_heap(var_class &vars) {
    //run script trace_heap_use
    var_class *vars_heap1 = new var_class();

    var_class *vars_heap_copy = new var_class(vars); 

    delete vars_heap1;
    delete vars_heap_copy;
}

void var_class_mv_test(var_class &vars)
{
    var_class_mv vars_mv(vars);

    std::cout << "derived class may use methods from base " << std::endl;
    vars_mv.print_array();
    
    var_class_mv vars_mv2 = std::move(vars_mv);

    show_container(*(vars_mv2.get_list()));

    show_container(*(vars_mv.get_list()));

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

    vars.add_word("Maja");
    vars.add_word("Gabrys");

    var_class_heap(vars);
    
    printf("size of class %ld\n\n", sizeof(var_class));

    var_class_mv_test(vars);


}
