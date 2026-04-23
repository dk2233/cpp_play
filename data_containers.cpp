#include <cstdio>
#include <list>
#include <ostream>
#include <vector>
#include "utils.h"
#include "templates.h"
#include <set>
#include <map>
#include <fstream>


using namespace std;


void containers()
{
    marker_begin("CONTAINERS");

    vector<int> numbers_vec = {};

    list<int> list_num = {};

    set<string> set_string = {"lion", "cat", "dog", "aligator"};

    map<string,string> map_strings = {pair<string,string>("animal","cat")}; 

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

    map_strings.insert(pair("word","car"));

    cout << "element in key " << map_strings.at("word") << endl;
    cout << "number of specific element " << map_strings.count("animal") << endl;

    map_strings["animal"] = "dog";

    cout << "element in key " << map_strings.at("animal") << endl;

    map_strings.at("word") = "empty";
    cout << "element in key " << map_strings.at("word") << endl;

    ofstream file1;

    file1.open("data.txt");

    for(auto it = map_strings.begin(); it != map_strings.end(); it++)
    {
        printf(" address %p \n", (void*)&(*it));
        file1 << "address " << &(*it) << std::endl;
        cout << "for loop - element : "  << it->first << " -> " << it->second << endl;
        file1 << "for loop - element : "  << it->first << " -> " << it->second << endl;

    }

    file1.close();

    marker_begin("CONTAINERS END");

}




