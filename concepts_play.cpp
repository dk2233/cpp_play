#include "templates.h"
#include "utils.h"
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>
#include <ranges>
#include <vector>
#include <concepts>
#include "concepts_play.h"



void wrong_example()
{
    std::list<double> list1 {1.2, -0.890, 45698444.0, 567.9, 689302.32};

    /* error during compilation
     due to concept usage 
     */
    //print_sort<std::list<double>>(list1);

}

void positive_example()
{
    std::vector<double> vec_double  {1.2, -0.890, 45698444.0, 567.9, 689302.32};

    print_sort(vec_double);
}

void AA_class_example()
{
    std::deque<AA> vec_AA {};
    std::deque<AA>::iterator it_AA = vec_AA.begin();
    vec_AA.emplace(it_AA, 45);
     it_AA = vec_AA.begin();
    vec_AA.emplace_back( 100);
    vec_AA.emplace_back(67);
    vec_AA.emplace_back( -200);
    
    show_container(vec_AA);

    print_sort(vec_AA);
}

auto add_with_concept( std::integral  auto x , std::integral auto y)
{
    return x + y;
}

auto add_with_other_concept( CanBeSum  auto x , CanBeSum auto y)
{
    return x + y;
}

double division_double_with_concept(std::floating_point auto number, std::floating_point auto divisor)
{
    try {
        if (divisor == 0)
        {
            throw(0);
        }
        return number/divisor;
    }
    catch (const int &err)
    {
        std::cerr << " You tried to divide by 0 " << std::endl;
        
         return 0.0;
    }

}

void display_char_from_number(std::convertible_to<char> auto cc) 
{
    std::cout << "from type " << typeid(cc).name() << " char: " << static_cast<char>(cc) << std::endl; 
}

void concepts_play()
{

    marker_begin("CONCEPTS BEGIN");
    wrong_example();

    positive_example();
    static_assert(Iterable<std::vector<int>>,  "Vector has to be iterable");

    AA_class_example();

    /* 
     * this wont work -> compiler see that we try to use double for integral
     * std::string str1 {add_with_concept(10.0, 2)};
     * 
     */
     
     
    std::cout << " add with concept " << add_with_concept(23, 67) 
        << std::endl;


    std::string str1 {"aaaa "};
    std::string str2 {"bbbb "};

    std::cout << add_with_other_concept(str1, str2)
        << std::endl;



    double dd {2.3};
    int ii {65};
    display_char_from_number(dd);

    display_char_from_number(ii);

    AA aa {45};
    AA aaa {40};

    //wont compile AA does not support +
    //    add_with_other_concept(       aa, aaa      );
    s_test struct1 {};
    Class_without_foo cl_test  = Class_without_foo('a');
    Class_with_foo cl_test2 = Class_with_foo('b');

    std::cout << struct1.foo() << std::endl;

    
     func_foo(struct1);

     //this wont compile
     //func_foo(   cl_test  );

     //this is fine even if foo in this object returns char
     func_foo(   cl_test2  );

    //this wont compile - compiler do not know how to convert object to char
    //display_char_from_number(aa);

    std::cout << " Division of double " << division_double_with_concept(34.67, 2.3) << std::endl;
    std::cout << " Division of double by 0 " << division_double_with_concept(34.67, 0.0) << std::endl;

    //this wont compile
    //double res_div {division_double_with_concept(5,6)};
    marker_begin("CONCEPTS END");
}
