#ifndef UTILS_H
#define UTILS_H
#include <iomanip>
#include <iostream>

constexpr short bar_size{80}; 

inline void marker_begin(const char* str) { 

    std::cout << std::setw(bar_size) << std::setfill('-') << str << std::endl << std::endl;

}
#endif

