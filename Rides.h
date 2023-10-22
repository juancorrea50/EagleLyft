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
    void createRide(Passenger* pObj, Driver* dObj);
    //Helper functions for addRide and
    bool compBool(Passenger* pObj, Driver* dObj, int pCount);
    struct tm getCurrentTime();
    void completeRide();
    //Increment and decrement functions
    void incRideCount();
    void decRideCount();
    //Remainder functions for utility
    void printRides();
    void printRidesByDriver(int id);
    void loadRides(vector<Passenger*>pVect,vector<Driver*> dVect);
    void saveRides();
    Ride* findRide(int id);
    void editRide(int id);
    void cancelRide(int id);
    void cleanUp();

    private:
    int rideCount;
    vector<Ride*> ridesVect;

};
#endif