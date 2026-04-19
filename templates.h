#ifndef TEMPLATES_H
#define TEMPLATES_H

#include "iostream"
using namespace std;

template <typename  C>
void show_container(const C& container);

template <typename  C>
void show_container(const C& container)
{
    for(auto&  n: container)
    {
        cout << n << ", ";
    }
    cout << endl;
}

#endif
