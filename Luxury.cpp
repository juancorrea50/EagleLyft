#include "Luxury.h"
#include <iostream>

Luxury::Luxury(int pSeats){
    passengerSeats = pSeats;
    cargoCap = "X-Large";
    ammenities = "TV, phone, bar, party lights, Bluetooth connections, wifi.";
    setVehicleCap(pSeats);
    setVehicleType("Limo");
}

void Luxury::printInfo(){
    cout <<"Luxury Class: " << "Passenger Seats(More than 7): " << passengerSeats << endl;
    cout << "Cargo Capacity: " << cargoCap << endl;
    cout << "Luxury Ammenities: " << ammenities << endl;
}