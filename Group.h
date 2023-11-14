#ifndef GROUP_H
#define GROUP_H
#include "Driver.h"
#include <string>

class Group: public Driver{
    public:
    Group(string nm, string vType, string ntes,int drID, bool isAvail, bool aPets, bool handAvail, float dRating,int pSeats);
    //printInfo
    void printInfo();
    private:
    int passengerSeats;
    string cargoCap;
};


#endif