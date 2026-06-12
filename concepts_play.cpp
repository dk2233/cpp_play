#include "templates.h"
#include "utils.h"
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>
#include <ranges>
#include <vector>
#include <concepts>
#include "concepts_play.h"

template <typename T>
concept SortableContainer = 
    std::ranges::random_access_range<T> &&               // 1. Kontener ma iteratory z dostępem swobodnym
    std::sortable<std::ranges::iterator_t<T>>;


template <typename T>
concept RAR = 
 std::ranges::random_access_range<T>;

template <typename T>
concept Iterable_new_ranges = std::sortable<std::ranges::iterator_t<T>>; 

template <typename T>
concept Iterable = std::totally_ordered<std::ranges::iterator_t<T>>; 


template <typename T>    
requires RAR<T> && Iterable<T>
void print_sort(T  &coll)
{
    //this cannot work with stack or list
    std::sort(coll.begin(), coll.end());

    std::cout << "sorted .. " << std::endl;
    for(auto &el: coll)
    {
        std::cout << std::setprecision(8) << el << std::endl;
    }
}


void wrong_example()
{
    std::list<double> list1 {1.2, -0.890, 45698444.0, 567.9, 689302.32};

    /* error during compilation
     due to concept usage 
     */
    //print_sort<std::list<double>>(list1);

}

void positive_example()
{
    std::vector<double> vec_double  {1.2, -0.890, 45698444.0, 567.9, 689302.32};

    print_sort(vec_double);
}

void AA_example()
{
    std::deque<AA> vec_AA {};
    std::deque<AA>::iterator it_AA = vec_AA.begin();
    vec_AA.emplace(it_AA, 45);
     it_AA = vec_AA.begin();
    vec_AA.emplace_back( 100);
    vec_AA.emplace_back(67);
    vec_AA.emplace_back( -200);
    
    show_container(vec_AA);

    print_sort(vec_AA);
}

void concepts_play()
{

    marker_begin("CONCEPTS BEGIN");
    wrong_example();

    positive_example();
    static_assert(Iterable<std::vector<int>>,  "Vector has to be iterable");

    AA_example();

    marker_begin("CONCEPTS END");
}
