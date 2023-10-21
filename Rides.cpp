#include <iostream>
#include <string>

#include "Rides.h"

Rides::Rides(){
    rideCount = 0;
}
Rides::Rides(int rCount, vector<Ride*> rVect){
    rideCount = rCount;
    ridesVect = rVect;
}
//Helper function to check boolean values from both Passenger and Driver 
bool Rides::compBool(Passenger* pObj, Driver* dObj){
    bool returnVal;
    int pCount;
    cout <<"How many passengers total?" << endl;
    cin >> pCount;

    if(dObj->getDriverRating() >= pObj->getRatingRequirement()){
        cout << "Driver meets passenger rating requirement." << endl;
        if(dObj->getIsAvailable() == true && dObj->getVehicleCap() >= pCount){
            cout << "Driver is available." << endl;
            if(dObj->getAllowPets() == pObj->getHasPets() || (dObj->getAllowPets() == true && pObj->getHasPets() == false)){
                cout << "Pets are allowed on this ride." << endl << "(If you do not have pets please consider a driver that does not allow them.)" << endl;
                if(dObj->getHandicapAvail() == pObj->getIsHandicap() || (dObj->getHandicapAvail() == true && pObj->getIsHandicap() == false)){
                    cout << "Handicap assistance is available on this ride."<< endl << "(If you are not handicap please consider a driver that does not have a handicap capable vehicle.)" << endl;
                    returnVal = true;
                }
            }
        }
    } else{
        cout << "Driver is either unavailable or Passenger's specifications do not match." << endl;
        returnVal = false;
    }
    return returnVal;

}
void Rides::addRide(Passenger* pObj, Driver* dObj){
    bool hasPassedCheck = compBool(pObj, dObj);
    if(hasPassedCheck == true){
        cout << "Ride has been created" << endl;
    } else{
        cout << "Ride cannot be created" << endl;
    }
}
