#ifndef IPRINTABLE
#define IPRINTABLE

#include <ostream>
class IPrintable 
{
    friend std::ostream &operator<<(std::ostream &os, IPrintable &p) ;
    public: 
        virtual void print(std::ostream &os)  const = 0;

        //very important - it will call in proper order
        //class destructor starting from iherited one
        virtual ~IPrintable() = default;
};
#endif
