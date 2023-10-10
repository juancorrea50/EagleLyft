#ifndef PASSENGERS_H
#define PASSENGERS_H
#include <vector>
#include "Passenger.h"

using namespace std;

class Passengers{
    public:
    //Construcors
    Passengers();
    Passengers(vector<Passenger*> pVect);
    //Add Passenger 1st prio testing
    void addPassenger();
    //Print
    void printPassengers();
    //Increment passenger ID
    int incPassId();
    private:
    int passengerCount;
    //Pointer vector
    vector<Passenger*> passVector;
};
#endif