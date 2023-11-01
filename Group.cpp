#include "Group.h"
#include <iostream>

Group::Group(int pSeats){
    passengerSeats = pSeats;
    cargoCap = "Large";
    setVehicleCap(pSeats);
    setVehicleType("SUV");
}

void Group::printInfo(){
    cout <<"Group Class: " <<"Passenger Seats(Between 5 and 7): " << passengerSeats << "Cargo Capacity: " << cargoCap << endl;
}