#ifndef GROUP_H
#define GROUP_H
#include "Driver.h"
#include <string>

class Group: public Driver{
    public:
    Group(int);
    //printInfo
    void printInfo();
    private:
    int passengerSeats;
    string cargoCap;
};


#endif