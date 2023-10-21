#include <iostream>
#include <string>
#include <iterator>
#include <time.h>
#include <ctime>
#include "Rides.h"

Rides::Rides(){
    rideCount = 0;
}
Rides::Rides(int rCount, vector<Ride*> rVect){
    rideCount = rCount;
    ridesVect = rVect;
}
void Rides::incRideCount(){
    rideCount++;
}
void Rides::decRideCount(){
    rideCount--;
}
//Helper function to check boolean values from both Passenger and Driver 
bool Rides::compBool(Passenger* pObj, Driver* dObj, int pCount){
    bool returnVal;
    
    if(dObj->getDriverRating() >= pObj->getRatingRequirement()){
        //cout << "Driver meets passenger rating requirement." << endl;
        if(dObj->getIsAvailable() == true && dObj->getVehicleCap() >= pCount){
            //cout << "Driver is available." << endl;
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
    
    Ride* temp;
    string pLoc;
    string rStat = "Active";
    int pCount;

    



    cout <<"How many passengers total?" << endl;
    cin >> pCount;

    bool hasPassedCheck = compBool(pObj, dObj,pCount);

    if(hasPassedCheck == true){
        //Instantiate object with pickup location, time, pCount, and rStat
        cout << "Enter the pickup location." << endl;
        cin.ignore();
        getline(cin,pLoc);
        int convHr;
        string amPm = "AM";

        incRideCount();
        temp = new Ride(pLoc,rStat,(rideCount + 100000), pCount);
        
        cout << "Ride pickup time is: " << endl;
        temp->setPickUpTime(temp->setTimeVal());
        if((temp->getPickUpTime()).tm_hour > 12){
            convHr = (temp->getPickUpTime()).tm_hour - 12;
            amPm = "PM";
        }
        cout << convHr << ":" << (temp->getPickUpTime()).tm_min << amPm << endl;

        ridesVect.push_back(temp);
    } else{
        cout << "Ride cannot be created" << endl;
    }
}
void Rides::printRides(){
    for(auto it = ridesVect.begin(); it != ridesVect.end(); ++it){
        cout << "Ride: " << endl;
        cout << "Ride ID: " << (*it)->getRideID();
        cout << "Party Size: " << (*it)->getPartySize();
        cout << "Pick up Location: " << (*it)->getPickUpLocation();
        cout << "Pick up Time: " << ((*it)->getPickUpTime()).tm_hour <<":"<< ((*it)->getPickUpTime()).tm_min << endl;
        cout << "Pick up Date: " << ((*it)->getPickUpTime()).tm_mon+1 <<" "<< ((*it)->getPickUpTime()).tm_mday<<", "<< ((*it)->getPickUpTime()).tm_year+1900 << endl;
    }
}
