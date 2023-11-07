#include "Basic.h"
#include <iostream>

Basic::Basic(string nm, string vType, string ntes,int drID, bool isAvail, bool aPets, bool handAvail, float dRating,int pSeats){
    passengerSeats = pSeats;
    cargoCap = "Medium";
    //Set all the driver class variables that were inherited
    setVehicleCap(pSeats);
    setVehicleType("Sedan");
    setName(nm);
    setNotes(ntes);
    setIsAvailable(isAvail);
    setAllowPets(aPets);
    setHandicapAvail(handAvail);
    setDriverRating(dRating);
}

void Basic::printInfo(){
    cout <<"Basic Class: " <<"Passenger Seats(Between 2 and 4): " << passengerSeats << "Cargo Capacity: " << cargoCap << endl;
}