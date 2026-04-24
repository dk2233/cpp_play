#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>

template<typename T>
T sum_all_elements(std::vector<T> v)
{
   T sum = 0;

   for(auto x:  v)
   {
       std::cout << x << " + " ;

   }
   std::cout << std::endl;
}

#endif
