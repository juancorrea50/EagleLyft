#include <iostream>
#include <string>

#include "Driver.h"

using namespace std;

Driver::Driver(){
    name = "none";
    vehicleType = "blank";
    notes = "none";
    vehicleCap = 0;
    dID = 100000;
    driverRating = 0;
    isAvailable = false;
    handicapAvail = false;
    allowPets = false;
}
Driver::Driver(string nm, string vType, string ntes, int drID, bool isAvail, bool aPets, bool handAvail, float dRating){
    name = nm;
    vehicleType = vType;
    notes = ntes;
    vehicleType = vType;
    dID = drID;
    isAvailable = isAvail;
    allowPets = aPets;
    handicapAvail = handAvail;
    driverRating = dRating;
    rideCount++;
}
//Setters
void Driver::setName(string nm){
    name = nm;
}
void Driver::setVehicleType(string vType){
    vehicleType = vType;
}
void Driver::setNotes(string nts){
    notes = nts;
}
void Driver::setVehicleCap(int vCap){
    vehicleCap = vCap;
}
void Driver::setDriverRating(float dRating){
    driverRating = (driverRating + dRating)/rideCount;
    rideCount++;
}
void Driver::setIsAvailable(char inVal){
    if(inVal == 'y' || inVal == 'Y'){
        isAvailable = true;
    } else if(inVal == 'n' || inVal == 'N'){
        isAvailable = false;
    }
}
void Driver::setAllowPets(char inVal){
    if(inVal == 'y' || inVal == 'Y'){
        allowPets = true;
    } else if(inVal == 'n' || inVal == 'N'){
        allowPets = false;
    }
}
void Driver::setHandicapAvail(char inVal){
    if(inVal == 'y' || inVal == 'Y'){
        handicapAvail = true;
    } else if(inVal == 'n' || inVal == 'N'){
        handicapAvail = false;
    }
}
