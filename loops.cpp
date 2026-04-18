#include <iostream>
#include "loops.h"
#include <cstdio>
#include "utils.h"

void test_loops() {

/*
 * for loops 
 */
    marker_begin("LOOPS\n");
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

    marker_begin("LOOPS END\n");
}
