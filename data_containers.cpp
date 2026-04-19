#include <list>
#include <ostream>
#include <vector>
#include "utils.h"
#include "templates.h"
#include <set>

using namespace std;


void containers()
{
    marker_begin("CONTAINERS");

    vector<int> numbers_vec = {};

    list<int> list_num = {};

    set<string> set_string = {"lion", "cat", "dog", "aligator"};

    numbers_vec.push_back(8);
    numbers_vec.push_back(90);

    numbers_vec.push_back(-78);

    show_container<vector<int>>(numbers_vec);

    list_num.push_front(8);

    list_num.push_back(90);

    list_num.push_front(-10);
    list_num.push_back(900);
    list_num.push_back(0);

    show_container<list<int>>(list_num);


    /*
     * we can simply use index like in array
     */
    cout << numbers_vec[0] << endl;


    cout << numbers_vec.at(0) << endl;


    show_container<set<string>>(set_string);

    cout << "size of set " << set_string.size() << endl;
    cout << "remove of one element " << *(next(set_string.begin())) <<  endl;
    set_string.erase(next(set_string.begin(),1));


    show_container<set<string>>(set_string);

    marker_begin("CONTAINERS END");

}




