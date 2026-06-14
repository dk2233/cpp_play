#include "enum_train.h"
#include "utils.h"
#include <iostream>
#include <ostream>


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

std::ostream &operator<<(std::ostream &os, const Colors_e &col)
{
    std::string str_color {};

    switch(col) {
        case Colors_e::BLACK:
            str_color = "Black";
            break;
        case Colors_e::WHITE:
            str_color = "White";
            break;
        case Colors_e::BLUE:
            str_color = "Blue";
            break;
        case Colors_e::GREEN:
            str_color = "Green";
            break;
        case Colors_e::RED:
            str_color = "Red";
            break;
        case Colors_e::YELLOW:
            str_color = "Yellow";
            break;
        default:
            break;

    }

    os << str_color;
    return os;
}

void enum_sandbox()
{
    marker_begin("ENUM STUDY BEGIN");
    Status_e stat {Status_e::STATUS_IDLE};

    std::cout << "State is " << stat << std::endl;

    
    Status_unscoped stat_un {STAT_IDLE};

    std::cout << "unscoped " << stat_un << std::endl;

    Colors_e color {Colors_e::WHITE};

    std::cout << " color enum " << color << std::endl; 
    color = Colors_e::GREEN;
    std::cout << " color enum " << color << std::endl; 


    marker_begin("ENUM STUDY END");


}
