
#ifndef VAR_CLASS_H
#define VAR_CLASS_H

#include <cstdint>
#include <string>
#include <list>
constexpr int arr_size = 20;
class var_class { 
    protected:
        std::list<std::string> *list_words = new std::list<std::string>(); 
        
    public:
        int data_int {0};
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

        void print_array();
        std::list<std::string> *  get_list() const;
        void add_word(const std::string& word);
};


class var_class_mv:public var_class {


    public:
        var_class_mv(int a, char c ) ;

        var_class_mv(int);

        var_class_mv(const var_class_mv& base);

        var_class_mv(const var_class& base);

        var_class_mv(var_class_mv&& base) noexcept;
        // Musisz to dodać pod konstruktorem przenoszącym
        var_class_mv& operator=(var_class_mv&& other) noexcept;

};

void var_class_test(); 
#endif




        


