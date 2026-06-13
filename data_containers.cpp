#include <algorithm>
#include <cstdio>
#include <list>
#include <ostream>
#include <vector>
#include "utils.h"
#include "templates.h"
#include <set>
#include <map>
#include <fstream>
#include "functions.h"


using namespace std;


std::ostream &operator<<(std::ostream &os, const std::set<int> &s) 
{
    std::set<int>::const_iterator it {s.begin()};
    os << " [ " ;
    while(it != s.end())
    {
        os << *it << " , ";
        it++;
    }
    os << " ] ";
    return os;
}

void vectors()
{
    vector<int> numbers_vec = {};

    numbers_vec.push_back(8);
    numbers_vec.push_back(90);

    numbers_vec.push_back(-78);

    show_container<vector<int>>(numbers_vec);
    
    auto it = numbers_vec.begin();

    while(it != numbers_vec.end())
    {
        std::cout << *it << " ,, ";
        it++;
    }

    /*
     * we can simply use index like in array
     */
    cout << numbers_vec[0] << endl;


    cout << numbers_vec.at(0) << endl;

    int s = sum_all_elements<int>(numbers_vec);

    numbers_vec.push_back(1200);

    sum_all_elements(numbers_vec);

    std::cout << "result = " << s << std::endl;
    

    std::transform(numbers_vec.begin(), numbers_vec.end(), numbers_vec.begin(),[](int x ) { 

        return x/2;

            });

    show_container(numbers_vec);

}


void maps()
{
    std::map<std::string, int> map_s_i {};
    std::map<std::string, std::set<int>> map_s_sets {};
    std::map<string,string> map_strings = {pair<string,string>("animal","cat")}; 

    map_s_i.emplace("Maja", 0);
    map_s_i["Gabrys"]++;
    map_s_i["Kinga"];

    show_container<std::string, int>(map_s_i);

    map_s_sets["Maja"] = {9};
    map_s_sets.emplace("Gabrys", std::set<int>{0, 3, 5, 78});
    map_s_sets.insert( std::pair<std::string, std::set<int>>{"Kinga", std::set<int>{90, -89, 56,23,56,7}});

    map_s_sets["Maja"].emplace(78);

    show_container<std::string, std::set<int>>(map_s_sets);
    
    std::cout << map_s_sets["Maja"] << std::endl;


  /*  for(auto &n: map_s_i)
    {
        std::cout << n.first << " , " << n.second << std::endl;
    }
    */
    map_strings.insert(pair("word","car"));

    cout << "element in key " << map_strings.at("word") << endl;
    cout << "number of specific element " << map_strings.count("animal") << endl;

    map_strings["animal"] = "dog";

    cout << "element in key " << map_strings.at("animal") << endl;
    map_strings.at("word") = "empty";
    cout << "element in key " << map_strings.at("word") << endl;

    ofstream file1 {"../data.txt", std::ios::app};

    if (file1.is_open())
    {

        for(auto it = map_strings.begin(); it != map_strings.end(); it++)
        {
            printf(" address %p \n", (void*)&(*it));
            file1 << "address " << &(*it) << std::endl;
            cout << "for loop - element : "  << it->first << " -> " << it->second << endl;
            file1 << "for loop - element : "  << it->first << " -> " << it->second << endl;

        }

        file1.close();
    }
    else {
    
        std::cerr << " Problem opening a file " << std::endl;
    }

}

void lists()
{
    /*
     * lists does not have random access
     * lists does not unvalidate iterators when adding\removing new element
     */
    list<int> list_num = {};

    list_num.push_front(8);

    list_num.push_back(90);

    list_num.push_front(-10);
    list_num.push_back(900);
    list_num.push_back(0);

    show_container<list<int>>(list_num);

    sum_all_elements_generic(list_num);
}

void containers()
{
    marker_begin("CONTAINERS");

    maps();

    vectors();

    lists();


    set<string> set_string = {"lion", "cat", "dog", "aligator"};



    std::cout << "using iterators " << std::endl;

    std::cout << std::endl;


    show_container<set<string>>(set_string);

    std::set<std::string>::iterator its {set_string.begin()};

    while(its != set_string.end())
    {
        std::cout << "loop with iterator "<< std::setw(20) << *(its++) << std::endl;
    }


    cout << "size of set " << set_string.size() << endl;
    cout << "remove of one element " << *(next(set_string.begin())) <<  endl;
    set_string.erase(next(set_string.begin(),1));


    show_container<set<string>>(set_string);


    marker_begin("CONTAINERS END");

}




