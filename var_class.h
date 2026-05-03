
#ifndef VAR_CLASS_H
#define VAR_CLASS_H

#include <cstdint>
#include <string>
#include <list>
constexpr int arr_size = 20;
class var_class { 
    private:
        std::list<std::string> *list_words = new std::list<std::string>(); 
        
    public:
        int  data_int {0};
        int data2 {3};
        unsigned int data_uint {2};
        float data_f;
        double data_double;
        char data_char {1};
        bool  data_bool {false};
        std::string data_string;
        char data_array[arr_size] {0};

        var_class(int a, char c);

        var_class();

        ~var_class();


        //var_class(const var_class& base);



        void print_array();
};

void var_class_test(); 
#endif




        


