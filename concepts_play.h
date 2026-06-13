#ifndef CONCEPT_PLAY
#define CONCEPT_PLAY

#include <iostream>
#include <iomanip>
#include <ostream>


class AA 
{
    private:
        int data_A;
    public:
        AA(int a = 0): data_A{a} {};
        ~AA()= default;

        int get_data() {
            return data_A;
        }

        void set_data(int a) {
            data_A = a;
        }

    friend std::ostream &operator<<(std::ostream &os, const AA &aa) {
        
        os << " A class with data " << std::setprecision(10) << aa.data_A ;
        return os;
    }

    bool operator<(const AA &rhs) const {
        return data_A < rhs.data_A;
    }
};

struct s_test {

    int foo() const {
        return 10;
    }
};

class Class_without_foo {
    private:
        char a;
    public:
        Class_without_foo(char c): a{c} {};
        char no_foo() const{
            return a;
        }
};

class Class_with_foo {
    private:
        char a;
    public:
        Class_with_foo(char c): a{c} {};
        char foo() const {
            return a;
        }
};
template <typename S>
concept HasFoo = requires(S ss)
{
    /* check if object supports foo method */
    {ss.foo()} -> std::integral;
};

template <HasFoo T>
void func_foo(const T &obj) 
{
    std::cout << "calling foo " << obj.foo() 
        << std::endl;
}

template <typename T>
concept CanBeMultiplied = requires(const T &t1, const T &t2){
    {t1 * t2 } -> std::same_as<T>;
};

template <typename T>
concept CanBeSum = requires(const T &t1, const T &t2){
    {t1 + t2 } -> std::same_as<T>;
};

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

void concepts_play();


#endif
