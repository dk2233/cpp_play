#include <iostream>
#include "enum_train.h"
#include "loops.h"
#include <cstdint>
#include "var_class.h" 
#include "types.h"
#include "data_containers.h"
#include "errors_train.h"


int main()
{
    uint32_t var = 100;
    auto var2 = 1.2f;
    int b = 0;

    Status_e status_test = Status_e::STATUS_INIT;

    types_test();

    std::cout << "var address " << &var << std::endl;
    uint32_t *var3 = &var;
    uint32_t *var_reinterpret = reinterpret_cast<uint32_t*>(&var);
    printf("before change pointer value, it should have same value like \"var\" \nvar different location %d, %d, %d \n", var, *var_reinterpret, *var3);
    *var3 = 200;

    printf("var different location %d, %d \n", var, *var3);


    {
        int b = 2;
        printf(" b = %d  \n", b);
    }

    test_loops();


    std::cout << "enum " << static_cast<int>(status_test) << std::endl ;

    status_test = Status_e::STATUS_RUN; 

    std::cout << "enum " << static_cast<int>(status_test) << std::endl ;

    var_class vars(10, 'a');
    var_class vars2(39, 'l');
    
    vars.print_array();
    vars2.print_array();
    
    printf("size of class %ld\n\n", sizeof(var_class));


    containers();


    check_exception();
}
