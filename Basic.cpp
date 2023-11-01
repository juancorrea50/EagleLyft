#include "Basic.h"
#include <iostream>

Basic::Basic(int pSeats){
    passengerSeats = pSeats;
    cargoCap = "Medium";
    setVehicleCap(pSeats);
    setVehicleType("Sedan");
}

void Basic::printInfo(){
    cout <<"Basic Class: " <<"Passenger Seats(Between 2 and 4): " << passengerSeats << "Cargo Capacity: " << cargoCap << endl;
}