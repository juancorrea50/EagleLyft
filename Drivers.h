#ifndef DRIVERS_H
#define DRIVERS_H

#include "Driver.h"
#include <vector>

class Drivers{
    public:
     //Construcors
    Drivers();
    Drivers(vector<Driver*> dVect);
    //Increment passenger ID
    int incDriverCount();
    //Decrement pass count
    void decDriverCount(){driverCount--;}
    //Add Passenger 1st prio testing
    void addDriver();
    //Print passVector
    void printDrivers();
    //Load in Passengers data file
    void loadDrivers();
    //Save Passengers into a data file
    void saveDrivers();
    //Helper function to find a Passenger in the vector
    Driver* findDriver(int id);
    //Edit function 
    void editDriver(int id);
    //Delete function
    void deleteDriver(int id);
    //Memory Cleanup
    void cleanUp();
    private:
    int driverCount;
    vector<Driver *> driverVect;
};
#endif