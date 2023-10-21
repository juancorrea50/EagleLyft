#ifndef RIDE_H
#define RIDE_H
#include <string>
#include <ctime>

using namespace std;

class Ride{
    public:
    Ride();
    Ride(string pLoc, string rStat, int rID, int pSize);
    //Drop off location, drop off time, and customer rating will be set on drop off
    //Setters
    void setPickUpLocation(string pLoc);
    void setDropOffLocation(string dLoc);
    void setRideStatus(string rStat);
    void setPartySize(int pSize);
    void setCustRating(float cRating);
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
    struct tm getPickUpTime(){return pickUpTime;}
    struct tm getDropOffTime(){return dropOffTime;}

    private:
    string pickUpLocation, dropOffLocation, rideStatus;    
    int rideID, partySize;
    float custRating;
    struct tm pickUpTime;
    struct tm dropOffTime;
};

#endif