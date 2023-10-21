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
    //Helper functions for addRide and
    bool compBool(Passenger* pObj, Driver* dObj, int pCount);
    void checkComplete();
    //Increment and decrement functions
    void incRideCount();
    void decRideCount();
    //Remainder functions for utility
    void printRides();
    void loadRides();
    void saveRides();
    void findRide();
    void editRide();
    void cancelRide();
    void cleanUp();

    private:
    int rideCount;
    vector<Ride*> ridesVect;

};
#endif