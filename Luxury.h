#ifndef LUXURY_H
#define LUXURY_H
#include "Driver.h"
#include <string>

class Luxury: public Driver{
    public:
    Luxury(string,string, string,int , bool, bool, bool, float, int);
    //printInfo
    void printInfo();
    private:
    int passengerSeats;
    string cargoCap;
    string ammenities;
};


#endif