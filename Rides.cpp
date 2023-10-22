#include <iostream>
#include <string>
#include <iterator>
#include <time.h>
#include <ctime>
#include <fstream>
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

        incRideCount();
        temp = new Ride(pLoc,rStat,(rideCount + 100000), pCount);
        
        cout << "Ride pickup time is: " << endl;
        temp->setPickUpTime(temp->setTimeVal());
        
        cout <<(temp->getPickUpTime())<< endl;

        ridesVect.push_back(temp);
        /*Save this code until load and save are implemented
            //Change driver's isAvailable var to false;
        */
    } else{
        cout << "Ride cannot be created" << endl;
    }
}
void Rides::printRides(){
    for(auto it = ridesVect.begin(); it != ridesVect.end(); ++it){
        cout << "Ride: " << endl;
        cout << "Ride ID: " << (*it)->getRideID() << endl;
        cout << "Ride Status: (R)" << (*it)->getRideStatus() << endl;
        cout << "Party Size: " << (*it)->getPartySize()<< endl;
        cout << "Pick up Location: " << (*it)->getPickUpLocation()<< endl;
        cout << "Pick up Time and Date: " << (*it)->getPickUpTime()<< endl;
        cout << "Drop off Time and Date: " <<(*it)->getDropOffTime()<< endl << endl;
    }
}

//Load Rides from file
void Rides::loadRides(){
    ifstream fin;
    //Variables to fin
    string pLoc, dLoc, rStat;
    float cRating;
    bool isAvail, allowHandicap, allowPets;
    int rId, pSize;

    string pTime, dTime;
    
    //Open data file named Drivers.dat
    fin.open("Rides.dat");
    //Input for passenger count fin.ignore() ignores the newline
    fin >> rideCount; fin.ignore();
    //Input and push loaded data into the vector
    for(int i=0;i<rideCount;i++){
        fin.ignore(); getline(fin,pLoc);
        fin.ignore(); getline(fin,dLoc);
        fin >>cRating>> rStat >> rId;
        fin.ignore(); getline(fin, pTime);
        fin.ignore(); getline(fin, dTime);
        ridesVect.push_back(new Ride(pLoc,rStat,rId,pSize, pTime, dTime));
    }
    //Close file
    fin.close();
}
void Rides::saveRides(){
    ofstream fout;
    //Save rideCount into the file
    fout.open("Rides.dat");
    fout << rideCount << endl;
    Ride* temp;

    //Use iterator for iterating through the vector
    for(auto it = ridesVect.begin(); it != ridesVect.end(); ++it){
        //temp becomes the passenger pointer that it points to
        temp = *it;
        //Saves all the variable data in order of object instanciation
        fout << temp->getPickUpLocation() << "\n" << temp->getDropOffLocation()<< "\n" << temp->getCustRating()<< " " << temp->getRideStatus()<< " " << temp->getRideID() << "\n"<< temp->getPickUpTime() << "\n" << temp->getDropOffTime() << endl;
    }
    //close output file
    fout.close();
}
void Rides::cleanUp(){
    for(auto it = ridesVect.begin(); it!= ridesVect.end(); ++it){
        delete *it;
    }
    ridesVect.clear();
    rideCount = 0;
}
