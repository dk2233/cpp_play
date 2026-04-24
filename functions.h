#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <cstddef>
#include <iostream>
#include <vector>

template<typename T>
T sum_all_elements(std::vector<T> &v)
{
   T sum = 0;
   size_t i = 0;
   for(auto x:  v)
   {
       std::cout << x; 
       if ((i++ + 1) != v.size())
       {
           std::cout << " + " ;
       }
       sum += x;
   }
   std::cout <<  ":sum = " << sum << std::endl;
   return sum;
}


template<typename T>
typename T::value_type sum_all_elements_generic(const T &cont)
{
   typename  T::value_type sum = 0;
   size_t i = 0;
   const size_t total = cont.size();
   for(auto x:  cont)
   {
       std::cout << x; 
       if ((i++ + 1) != total) 
       {
           std::cout << " + " ;
       }
       sum += x;
   }
   std::cout <<  ":sum = " << sum << std::endl;
   return sum;
}

extern void circular() ;
#endif
