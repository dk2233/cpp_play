#include <iostream>
#include "loops.h"
#include <cstdio>

void test_loops() {

/*
 * for loops 
 */
    for(int i = 0; i < max_for ; i++)
    {
        std::cout << "for loop -" << i << " , ";
    }
    std::cout << "\n";

    int i = max_for;
    do {
        printf("do - while %d , ", i);

    } while ( i-- > 0);
    std::cout << "\n";

}
