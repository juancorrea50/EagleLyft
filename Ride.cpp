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
    dropOffLocation = " ";
    custRating = 0.00;
}
Ride::Ride(string pLoc, string rStat, int rID, int pSize, string pTime, string dTime){
    pickUpLocation = pLoc;
    rideStatus = rStat;
    rideID = rID;
    partySize = pSize;
    dropOffLocation = " ";
    custRating = 0.00;
    pickUpTime = pTime;
    dropOffTime = dTime;
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
//Helper function to set time
struct tm Ride::setTimeVal(){
    time_t now = time(NULL);
    struct tm nowLocal = *localtime(&now);
    return nowLocal;
}
//Setters for time values
void Ride::setPickUpTime(struct tm nLocal){
    char pt[80];
    strftime(pt,80,"%m-%d-%y %I:%M%p", &nLocal);
    pickUpTime = pt;
}
void Ride::setDropOffTime(struct tm nLocal){
    char dt[80];
    strftime(dt,80,"%m-%d-%y %I:%M%p", &nLocal);
    pickUpTime = dt;
}

