#include "Group.h"
#include <iostream>

Group::Group(string nm, string vType, string ntes,int drID, bool isAvail, bool aPets, bool handAvail, float dRating,int pSeats){
    passengerSeats = pSeats;
    cargoCap = "Large";
    setVehicleCap(pSeats);
    setVehicleType("SUV");
    //Set all other private variables of the driver class
    setName(nm);
    setNotes(ntes);
    setIsAvailable(isAvail);
    setAllowPets(aPets);
    setHandicapAvail(handAvail);
    setDriverRating(dRating);
}

void Group::printInfo(){
    cout <<"Group Class: " <<"Passenger Seats(Between 5 and 7): " << passengerSeats << "Cargo Capacity: " << cargoCap << endl;
}