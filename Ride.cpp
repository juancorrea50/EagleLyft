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
Ride::Ride(string pLoc, string rStat, int rID, int pSize){
    pickUpLocation = pLoc;
    rideStatus = rStat;
    rideID = rID;
    partySize = pSize;
    //dropOffLocation = dLoc;
    //custRating = cRating;
    //pickUpTime = pUpTime;
    //dropOffTime = dOffTime;
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

//Setters for time values
void Ride::setPickUpTime(){
    time_t now = time(NULL);
    struct tm nowLocal = *localtime(&now);

    pickUpTime = nowLocal;
}
void Ride::setDropOffTime(){
    time_t now = time(NULL);
    struct tm nowLocal = *localtime(&now);

    dropOffTime = nowLocal;
}

