#include "functions.h"
#include <iostream>
#include <string>
#include <vector>
#include "templates.h"
#include "utils.h"

int sum_between(int m, int n);
int sum_between_rec(int m, int n);

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
    marker_begin("FUNCTIONS END");
}
