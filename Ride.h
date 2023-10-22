#ifndef RIDE_H
#define RIDE_H
#include <string>
#include <ctime>
#include "Driver.h"
#include "Passenger.h"

using namespace std;

class Ride{
    public:
    Ride();
    Ride(string pLoc,string dLoc, string rStat, int rID, int pSize);
    Ride(string pLoc, string rStat, int rID, int pSize, string pTime, string dTime);
    //Drop off location, drop off time, and customer rating will be set on drop off
    //Setters
    void setPickUpLocation(string pLoc);
    void setDropOffLocation(string dLoc);
    void setRideStatus(string rStat);
    void setPartySize(int pSize);
    void setCustRating(float cRating);
    void setDriver(Driver* dObj);
    void setPassenger(Passenger* pObj);
    //Time Functions
    //Returns a tm struct that contains the current time and date
    struct tm setTimeVal();
    //Functions are setters of current time for pick up and drop off times
    void setPickUpTime(struct tm nLocal);
    void setDropOffTime(struct tm nLocal);
    //Getters
    string getPickUpLocation(){return pickUpLocation;}
    string getDropOffLocation(){return dropOffLocation;}
    string getRideStatus(){return rideStatus;}
    int getRideID(){return rideID;}
    int getPartySize(){return partySize;}
    float getCustRating(){return custRating;}
    string getPickUpTime(){return pickUpTime;}
    string getDropOffTime(){return dropOffTime;}
    Passenger* getPassenger(){return passenger;}
    Driver* getDriver(){return driver;}
    struct tm getTimeStruct(){return timeVal;}
    int getPickUpHr(){return pickUpHr;}

    private:
    string pickUpLocation, dropOffLocation, rideStatus;    
    int rideID, partySize;
    float custRating;
    string pickUpTime;
    string dropOffTime;
    Driver* driver;
    Passenger* passenger;
    struct tm timeVal;
    int pickUpHr;
};

#endif