#include <iostream>

#include "Ride.h"

Ride::Ride(){
    pickUpLocation = " ";
    dropOffLocation = " ";
    rideStatus = " ";
    rideID = 0;
    partySize = 0;
}
Ride::Ride(string pLoc,string dLoc, string rStat, int rID, int pSize){
    pickUpLocation = pLoc;
    dropOffLocation = dLoc;
    rideStatus = rStat;
    rideID = rID;
    partySize = pSize;
    dropOffTime = "None";
}
Ride::Ride(string pLoc, string dLoc, string rStat, int rID, int pSize, string pTime, string dTime, int pUHr,int pUDay){
    pickUpLocation = pLoc;
    rideStatus = rStat;
    rideID = rID;
    partySize = pSize;
    dropOffLocation = dLoc;
    pickUpTime = pTime;
    dropOffTime = dTime;
    pickUpHr = pUHr;
    pickUpDay = pUDay;
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
//Helper function to set time
struct tm Ride::setTimeVal(){
    time_t now = time(NULL);
    struct tm nowLocal = *localtime(&now);
    timeVal = nowLocal;
    return nowLocal;
}
//Setters for time values
void Ride::setPickUpTime(struct tm nLocal){
    pickUpHr = nLocal.tm_hour;
    pickUpDay = nLocal.tm_mday;
    char pt[80];
    strftime(pt,80,"%m-%d-%y %I:%M%p", &nLocal);
    pickUpTime = pt;
}
void Ride::setDropOffTime(struct tm nLocal){
    char dt[80];
    strftime(dt,80,"%m-%d-%y %I:%M%p", &nLocal);
    dropOffTime = dt;
}
void Ride::setDriver(Driver* dObj){
    driver = dObj;
}
void Ride::setPassenger(Passenger* pObj){
    passenger = pObj;
}