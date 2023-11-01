#ifndef BASIC_H
#define BASIC_H
#include "Driver.h"
#include <string>

class Basic: public Driver{
    public:
    Basic(int);
    //printInfo
    void printInfo();
    private:
    int passengerSeats;
    string cargoCap;
};


#endif