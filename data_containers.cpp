#include <list>
#include <vector>
#include "utils.h"

using namespace std;


void containers()
{
    marker_begin("containers");

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


}




