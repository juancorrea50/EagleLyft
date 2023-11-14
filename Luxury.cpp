#include "Luxury.h"
#include <iostream>

Luxury::Luxury(string nm, string vType, string ntes,int drID, bool isAvail, bool aPets, bool handAvail, float dRating,int pSeats){
    passengerSeats = pSeats;
    cargoCap = "X-Large";
    ammenities = "TV, phone, bar, party lights, Bluetooth connections, wifi.";
    setVehicleCap(pSeats);
    setVehicleType("Limo");
    //Set the rest of the variables
    setName(nm);
    setNotes(ntes);
    setIsAvailable(isAvail);
    setAllowPets(aPets);
    setHandicapAvail(handAvail);
    setDriverRating(dRating);
}

void Luxury::printInfo(){
    cout <<"Luxury Class: " << "Passenger Seats(More than 7): " << passengerSeats << endl;
    cout << "Cargo Capacity: " << cargoCap << endl;
    cout << "Luxury Ammenities: " << ammenities << endl;
}