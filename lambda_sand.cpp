#include "templates.h"
#include "utils.h"
#include <deque>
#include <functional>
#include <iostream>


void lambda_sand()
{
    marker_begin("LAMBDA BEGIN");

    [](char ch){
        std::cout << ch << " -> "
            << static_cast<char>(ch-0x20) << std::endl;
        
    }('a');


      std::function lambda1 =   [](char ch){
        std::cout << ch << " -> "
            << static_cast<char>(ch-0x20) << std::endl;
        
    };

      std::function<void(char)> lambda2 = []  (char x) mutable {
          x = x + 1;

          std::cout << x << " || ";
    
      };

      char a {'a'};

      lambda1('b');

      lambda2('c');

      lambda2(40);

      lambda2(a);

      std::cout << a << " || ";
    
      std::function<void(char &)> lambda3 = []  (char &x) mutable {
          x = x + 1;

          std::cout << x << " || ";
    
      };
      std::cout << std::endl;
      lambda3(a);
      std::cout << a << std::endl;

    std::deque<double> deq_doub {1.2, -7.8, 1234.7899, 4.0, 3.6};


     show_container(deq_doub);
     std::sort(deq_doub.begin(), deq_doub.end(), [](const double &d1, const double &d2){
             return d1 < d2;
             });

     show_container(deq_doub);
    marker_begin("LAMBDA END");

}
