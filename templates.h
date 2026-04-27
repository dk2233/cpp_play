#ifndef TEMPLATES_H
#define TEMPLATES_H

#include "iostream"
#include <array>
#include <type_traits>

using namespace std;

template <typename  C>
void show_container(const C& container);

template <typename  C>
void show_container(const C& container)
{
    for(auto&  n: container)
    {
        cout << n << ", ";
    }
    cout << endl;
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
