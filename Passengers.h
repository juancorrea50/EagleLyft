#ifndef PASSENGERS_H
#define PASSENGERS_H
#include <string>
#include <map>
#include "Passenger.h"

using namespace std;

class Passengers{
    public:
    Passengers(map<int, Passenger*> pVector);
    //Add Passenger 1st prio testing
    void addPassenger(Passenger* pass) const;
    private:
    map<int,Passenger*> passengerMap;
};
#endif