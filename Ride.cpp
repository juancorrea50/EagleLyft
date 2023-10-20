#include <iostream>

#include "Ride.h"

Ride::Ride(){
    pickUpLocation = " ";
    dropOffLocation = " ";
    rideStatus = " ";
    rideID = 0;
    partySize = 0;
    custRating = 0.00;
}
Ride::Ride(string pLoc, string dLoc, string rStat, int rID, int pSize, float cRating, struct tm pUpTime, struct tm dOffTime){
    pickUpLocation = pLoc;
    dropOffLocation = dLoc;
    rideStatus = rStat;
    rideID = rID;
    partySize = pSize;
    custRating = cRating;
    pickUpTime = pUpTime;
    dropOffTime = dOffTime;
}
//Setters
void Ride::setPickUpLocation(string pLoc){
    pickUpLocation = pLoc;
}
void Ride::setDropOffLocation(string dLoc){
    dropOffLocation = dLoc;
}
void Ride::setRideStatus(string rStat){
    rideStatus = rStat;
}
void Ride::setPartySize(int pSize){
    partySize = pSize;
}
void Ride::setCustRating(float cRating){
    custRating = cRating;
}
//Time Functions
//Helper function to get a time struct
struct tm Ride::setTimeVal(){
    time_t now = time(NULL);
    struct tm nowLocal = *localtime(&now);
    return nowLocal;
}
//Setters for time values
void Ride::setPickUpTime(){
    pickUpTime = setTimeVal();
}
void Ride::setDropOffTime(){
    dropOffTime = setTimeVal();
}

