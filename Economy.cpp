#include "Economy.h"
#include <iostream>


Economy::Economy(int pSeats){
    //Need to add an input check to ensure the range of the passenger seats is allowed for the ride
    passengerSeats = pSeats;
    cargoCap = "Small";
    setVehicleCap(pSeats);
    setVehicleType("Coupe");

}

void Economy::printInfo(){
    cout <<"Economy Class: " <<"Passenger Seats(2 or less): " << passengerSeats << "Cargo Capacity: " << cargoCap << endl;
}
