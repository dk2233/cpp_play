#include <iostream>
#include <cctype>
#include <string>
#include <utility>
#include <vector>


std::string test_tab[] = {
    "AA-A567 -ABN R ERW",
    "2345678--4443",
    "AFG--- ER  WEDCD  RTGS ",
    "-1234567-",
    "AA-B-B",
    "AA-B-BCF",
    "A A-",
    "--B",
};


constexpr size_t max_one_block {3};

std::string reformat(std::string &str)
{
    std::string new_s {};
    std::vector<std::string> new_str_vec {};

    size_t i {};
    size_t j {};

    new_str_vec.push_back({});

    while(i < str.length())
    {
        if (std::isalpha(str.at(i)) || std::isdigit(str.at(i)))
        {
            new_str_vec.back().push_back(str.at(i));

            if (++j == max_one_block)
            {
                //new_s += ' ';
                new_str_vec.push_back({});

                j = 0;
            }
        }

        i++;
    }

    if (new_str_vec.back().empty()) new_str_vec.pop_back();

    if ((new_str_vec.back().length() == 1) && (new_str_vec.size() > 1)) 
    {
        size_t one_bf_last_el {new_str_vec.size() - 2};
        char a {new_str_vec.at(one_bf_last_el).back()};


        new_str_vec.at(one_bf_last_el).pop_back();
        new_str_vec.back().insert(new_str_vec.back().begin(), a);

    }

    new_str_vec.back().push_back(';');
    
    for(std::string &s: new_str_vec)
    {
        new_s += s ;
        new_s +=  ' ';
    }
    
    if (new_s.back() == ' ') new_s.pop_back();

    return new_s;        
}

void license_key()
{

    for(std::string &s: test_tab)
    {
        std::cout << s << "\n" << reformat(s) << "\n";
    }

}
