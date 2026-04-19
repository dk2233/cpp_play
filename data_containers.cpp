#include <list>
#include <ostream>
#include <vector>
#include "utils.h"
#include "templates.h"

using namespace std;


void containers()
{
    marker_begin("CONTAINERS");

    vector<int> numbers = {};

    list<int> list_num = {};

    numbers.push_back(8);
    numbers.push_back(90);

    numbers.push_back(-78);

    show_container<vector<int>>(numbers);

    list_num.push_front(8);

    list_num.push_back(90);

    list_num.push_front(-10);
    list_num.push_back(900);
    list_num.push_back(0);

    show_container<list<int>>(list_num);


    /*
     * we can simply usee index like in arrayy
     */
    cout << numbers[0] << endl;

    marker_begin("CONTAINERS END");

}




