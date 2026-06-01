#include "enum_train.h"
#include "utils.h"
#include <iostream>


std::ostream &operator<<(std::ostream &os, Status_e &status)
{
    switch(status) {
    
        case Status_e::STATUS_INIT: 
            os << "Init state"; 
            break;
        case Status_e::STATUS_IDLE:
            os << "Idle state";
            break;
        default:
            os << "Unknown state";
            break;
    }

    return os;


}

void enum_sandbox()
{
    marker_begin("ENUM STUDY BEGIN");
    Status_e stat {Status_e::STATUS_IDLE};

    std::cout << "State is " << stat << std::endl;

    
    Status_unscoped stat_un {STAT_IDLE};

    std::cout << "unscoped " << stat_un << std::endl;

    marker_begin("ENUM STUDY END");


}
