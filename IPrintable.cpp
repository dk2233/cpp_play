#include "IPrintable.h"

std::ostream &operator<<(std::ostream &os, IPrintable &p) 
{
    p.print(os);

    return os;
}
