#ifndef GROUP_H
#define GROUP_H
#include "Driver.h"
#include <string>

class Luxury: public Driver{
    public:
    Luxury(int);
    //printInfo
    void printInfo();
    private:
    int passengerSeats;
    string cargoCap;
    string ammenities;
};


#endif