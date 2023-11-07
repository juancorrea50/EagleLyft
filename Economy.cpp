#include "Economy.h"
#include <iostream>


Economy::Economy(string nm, string vType, string ntes,int drID, bool isAvail, bool aPets, bool handAvail, float dRating,int pSeats){
    //Need to add an input check to ensure the range of the passenger seats is allowed for the ride
    passengerSeats = pSeats;
    cargoCap = "Small";
    //Set the vehicle cap and type from the driver class
    setVehicleCap(pSeats);
    setVehicleType("Coupe");
    //Set all other private variables of the driver class
    setName(nm);
    setNotes(ntes);
    setIsAvailable(isAvail);
    setAllowPets(aPets);
    setHandicapAvail(handAvail);
    setDriverRating(dRating);

}

void Economy::printInfo(){
    cout <<"Economy Class: " <<"Passenger Seats(2 or less): " << passengerSeats << "Cargo Capacity: " << cargoCap << endl;
}
