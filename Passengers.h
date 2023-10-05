#ifndef PASSENGERS_H
#define PASSENGERS_H
#include <vector>
#include "Passenger.h"

using namespace std;

class Passengers{
    public:
    Passengers();
    Passengers(vector<Passenger*> pVect, int pCount);
    //Add Passenger 1st prio testing
    void addPassenger();
    private:
    int passengerCount;
    //Pointer vector
    vector<Passenger *> passVector;
};
#endif