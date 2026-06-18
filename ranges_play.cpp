#include <iostream>
#include <algorithm>
#include <memory>
#include <vector>
#include "BankAccount.h"

  


template <typename  T> 
concept Printable = requires(std::ostream &os,const T &c)
{
    {os << c} ->std::same_as<std::ostream&>;
};
template <typename C>
requires Printable<std::ranges::range_value_t<C>> 
void display_ranges(const C &tt)
{
    std::ranges::for_each(tt, [](int x) {
            std::cout << x << " , ";
            });
    std::cout << std::endl;

}


void ranges_play()
{
    std::vector<std::unique_ptr<BankAccount>> account_vec {};
    account_vec.push_back(std::make_unique<CheckAccount>("konto1" , 1000));
    account_vec.push_back(std::make_unique<TrustAccount>("konto2" , 4000, 2.0));
    account_vec.push_back(std::make_unique<SavingsAccount>("konto3" , 2000, 1.0));

    std::vector<int> tab_int {9, 78, -67, 0, 3, 12345};

    display_ranges(tab_int);

    std::ranges::sort(tab_int);


    display_ranges(tab_int);

    auto it =  
        std::ranges::max_element(account_vec, {}, &BankAccount::get_balance);
    std::cout << "max element of account_vec " << *(it->get() )
        << std::endl;
}
