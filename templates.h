#ifndef TEMPLATES_H
#define TEMPLATES_H

#include "iostream"
#include <array>
#include <concepts>
#include <ostream>
#include <type_traits>
#include <map>
#include <set>
#include <iomanip>
#include <ranges>

using namespace std;

std::ostream &operator<<(std::ostream &os, const std::set<int> &s);

template <typename  C>
concept Printable = requires(std::ostream &os,const C &c)
{
    {os << c} ->std::same_as<std::ostream&>;
};
template <typename C>
requires Printable<std::ranges::range_value_t<C>> 
void show_container(const C& container)
{
    for(const auto& element: container)
    {
        std::cout << std::setprecision(7) << element << ", ";
    }
    std::cout << std::endl;
}

template <typename T1, typename T2>
void show_container(const std::map<T1, T2> &m)
{
    for(auto &el: m)
    {
        std::cout << el.first << " , " << el.second << std::endl;
    }
}


template <typename T, size_t N>
class CircularBuffer {
    // Tutaj static_assert, żeby sprawdzić czy T to typ liczbowy
    static_assert(std::is_arithmetic<T>::value, "Buffer must store numeric types!");

private:
    std::array<T, N> data{};
    size_t head = 0;
    size_t count = 0;

public:
    void add(T value) {
        // Implementacja bufora kołowego
        // ...
        data[head] = value;
        head = (head + 1)  % N;

        if (count < N) count++;


    }

    T get_average() const {
        // Implementacja średniej
        // ...
        T avg = 0;
        for(size_t i =0; i < count ; i++)
        {
            avg += data[i];

        }

        return avg/count;

    }

    void print_all() const {
        // Wykorzystaj pętlę range-based for
        // ...
        for(size_t i = 0; i < count; i++)
        {
            std::cout << data.at(i) << ", " ;
        }
        std::cout << std::endl;
    }
};

/**
int main() {
    // Przykład użycia: Bufor na 5 pomiarów temperatury (float)
    CircularBuffer<float, 5> engine_temp;

    engine_temp.add(85.5f);
    engine_temp.add(90.2f);
    
    engine_temp.print_all();
    std::cout << "Srednia: " << engine_temp.get_average() << std::endl;

    return 0;
}
**/
template <typename T>
void print_size_template(const T& data)
{

    std::cout <<  "size of " << typeid(data).name() << " " << sizeof(data) << std::endl;
};
#endif
