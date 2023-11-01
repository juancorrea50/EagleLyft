#ifndef ECONOMY_H
#define ECONOMY_H
#include "Driver.h"
#include <string>

class Economy: public Driver{
    public:
    Economy(int);
    //printInfo
    void printInfo();
    private:
    int passengerSeats;
    string cargoCap;
};


#endif