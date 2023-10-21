#ifndef RIDES_H
#define RIDES_H

#include <vector>
#include "Ride.h"
#include "Passengers.h"
#include "Drivers.h"

class Rides{
    public:
    //Constructors
    Rides();
    Rides(int rCount, vector<Ride*> rVect);
    //Collection Functions
    void addRide(Passenger* pObj, Driver* dObj);
    //Helper functions for addRide
    bool compBool(Passenger* pObj, Driver* dObj);
    void checkComplete();
    //Remainder functions for utility
    void printRides();
    void loadRides();
    void saveRides();
    void findRide();
    void editRide();
    void deleteRide();
    void cleanUp();

    private:
    int rideCount;
    vector<Ride*> ridesVect;

};
#endif