#ifndef CONCEPT_PLAY
#define CONCEPT_PLAY


#include <iomanip>
#include <ostream>
class AA 
{
    private:
        int data_A;
    public:
        AA(int a = 0): data_A{a} {};
        ~AA()= default;

        int get_data() {
            return data_A;
        }

        void set_data(int a) {
            data_A = a;
        }

    friend std::ostream &operator<<(std::ostream &os, const AA &aa) {
        
        os << " A class with data " << std::setprecision(10) << aa.data_A ;
        return os;
    }

    bool operator<(const AA &rhs) const {
        return data_A < rhs.data_A;
    }

    


};

void concepts_play();


#endif
