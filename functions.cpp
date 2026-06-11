#include "functions.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include "Shapes.h"
#include "templates.h"
#include "utils.h"
#include <list>

int sum_between(int m, int n);
int sum_between_rec(int m, int n);
void test_of_references(std::string &str);
void func_normal_arg(std::string str);

void circular() {

    marker_begin("CIRCULAR");
 
    CircularBuffer<float , 20> temp1;

    temp1.add(1.4);
    temp1.add(2.6);

    cout << "avg " << temp1.get_average() << std::endl;

    temp1.add(4.4);
    temp1.add(2.9);

    cout << "avg " << temp1.get_average() << std::endl;

    temp1.print_all();

    CircularBuffer<int,  10> temp2;

    temp2.add(10);
    temp2.add(12);
    temp2.add(13);
    temp2.add(5);
    temp2.print_all();
    cout << "avg int " << temp2.get_average() << std::endl;


    marker_begin("CIRCULAR END");
}


int sum_args(int a, int b)
{
    return a + b;
}

char sum_args(char a, char b)
{
    return a + b;
}


float sum_args(float a, float b)
{
    return a + b;
}

int sum_between(int m, int n)
{
    int t ;
    if (m > n) 
    {
        t = n;
        n = m;
        m = t;

    }
    t = 0;
    for(; m <= n; m++)
    {
        t += m; 
    }
    return t;
}

 int sum_between_rec(int m, int n)
{

    if (m == n) {
        return m;
    }
    return m + sum_between_rec(m+1, n) ;
}

void test_of_references(std::string &str)
{

    std::cout << "string" << std::endl ;
    std::cout << str << std::endl;


}

void func_normal_arg(std::string str)
{

    std::cout << "string" << std::endl ;
    std::cout << str << std::endl;

}

class DoubleValue
{
    public:
        int operator()(int x) {
            return x*2;
        }
};

struct MathSquare
{
    double operator()(double x){
        return x*x;
    }
};

struct WordsSum
{
    std::string word;

    WordsSum(std::string s = "empty"):word(s){};

    std::string operator()(std::string w)
    {
        
        return  word + w;
    }
};

void display_number_if(const std::list<int> &l, std::function<bool(int)> func)
{
    std::list<int>::const_iterator it {l.begin()};
    std::cout << "Here I am using a func to decide what to display or not " << std::endl;
    while( it != l.end())
    {
        if (func(*it)) std::cout << *it << " . ";
        it++;
    }
    std::cout << std::endl;

}

void functions_main()
{
    marker_begin("FUNCTIONS");
    std::cout <<  " sum of int " <<  sum_args(2,40) << std::endl;
    std::cout <<  " sum of float " <<  sum_args(2.5f, 5.78f) << std::endl;
    char x1 = 4, x2 = 6;

    std::cout <<  " sum of char " <<  static_cast<int>(sum_args(x1, x2)) << std::endl;
    int a1 = 2, a2 = 8;
    std::cout << " sum between " << a1 << " and " << a2 << " = " << sum_between(2, 8) << std::endl;

    std::cout << " sum between " << a1 << " and " << a2 << " = " << sum_between_rec(2, 8) << std::endl;
   
    
    std::string str1 {"teext"};
    test_of_references(str1);
    func_normal_arg(str1);


    std::cout << "function object example : " << DoubleValue()(10) << std::endl;
    std::cout << "function object example 2 : " << MathSquare()(10) << std::endl;
    std::cout << "function object example 3 : " << WordsSum()("Dan_") << std::endl;
    WordsSum fun_w = WordsSum("Maja");
    

    std::cout << "function object example 4 : " << fun_w("_and_Gabrys") << std::endl;

    /*
     * lambda 
     */ 

    std::function<bool(int)> lambda_func = [](int x) {
        if (x < 30) return true;
        return false; 
    };

    std::list<int> lista1 { 0 ,20, 40, 78, 9, 11};

    show_container(lista1);


    display_number_if( lista1,  lambda_func);

    marker_begin("FUNCTIONS END");
}
