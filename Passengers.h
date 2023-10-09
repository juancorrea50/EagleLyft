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
    //Get for pID
    int getpID() const {return pID;}
    //Increment passenger ID
    void incPassId();
    private:
    int passengerCount;
    int pID;
    //Pointer vector
    vector<Passenger*> passVector;
};
#endif