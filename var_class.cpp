#include "var_class.h"
#include "templates.h"
#include "utils.h"
#include <iostream>
#include <string>
#include <utility>

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
    data2 = 2;
    
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
var_move_def::var_move_def(const var_class& base):var_class(base) {
    list_words = new std::list<std::string>(*(base.get_list()));
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

var_class_mv& var_class_mv::operator=(var_class_mv&& other) noexcept {
    // 1. Sprawdź, czy nie przypisujesz obiektu do samego siebie (np. a = std::move(a))
    if (this != &other) {
        // 2. Najpierw wyczyść własne śmieci (zwolnij starą listę)
        delete this->list_words;

        // 3. Ukradnij zasoby od 'other'
        this->list_words = other.list_words;

        // 4. Ustaw 'other' na nullptr, żeby destruktor go nie usunął
        other.list_words = nullptr;
        
        std::cout << "Move Assignment Operator called!" << std::endl;
    }
    return *this;
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

    std::cout << "before use again vars_mv that was moved to vars_mv2 , we need to return ownership otherwise we will crash reading from null" << std::endl; 
    if (vars_mv.get_list() != nullptr)
    {

        show_container(*(vars_mv.get_list()));
    }
    else 
    {
        std::cout << "address is null , it was moved to other instance" << std::endl;


    }
    vars_mv2.add_word("new word");

    
    vars_mv = std::move(vars_mv2);
    if (vars_mv.get_list() != nullptr)
    {

        show_container(*(vars_mv.get_list()));
    }
    else 
    {
        std::cout << "address is null , it was moved to other instance" << std::endl;


    }


    var_move_def var_mv3 = var_class(vars);

    std::cout << "now call default move" <<  std::endl;
    var_move_def vars_mv4 = std::move(var_mv3);

    show_container(*(vars_mv4.get_list()));
    show_container(*(var_mv3.get_list()));

}

void var_class_test() 
{
    marker_begin("VAR_CLASS START");
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
    marker_begin("VAR_CLASS END");


}
