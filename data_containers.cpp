#include <list>
#include <vector>
#include "utils.h"

using namespace std;


void containers()
{
    marker_begin("CONTAINERS");

    vector<int> numbers = {};

    list<int> list_num = {};

    numbers.push_back(8);
    numbers.push_back(90);

    numbers.push_back(-78);

    for(int n : numbers)
    {
        cout << n << ", ";

    }
    cout << endl;
    /*
     * we can simply usee index like in arrayy
     */
    cout << numbers[0] << endl;

    marker_begin("CONTAINERS END");

}




