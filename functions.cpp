#include <iostream>
#include <string>
#include <vector>
#include "templates.h"
#include "utils.h"


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



