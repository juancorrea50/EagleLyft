#ifndef PASSENGERS_H
#define PASSENGERS_H
#include <map>
#include "Passenger.h"

using namespace std;

class Passengers{
    public:
    Passengers();
    Passengers(int pCount);
    //Add Passenger 1st prio testing
    void addPassenger() const;
    private:
    int passengerCount;
    map<int,Passenger*> passengerMap;
};
#endif