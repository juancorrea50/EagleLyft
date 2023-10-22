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
//Current time to display on menu
struct tm Rides::getCurrentTime(){
    time_t now = time(NULL);
    struct tm nowLocal = *localtime(&now);
    
    return nowLocal;
}
//Complete rides if an hour(assumed value) has passed
void Rides::completeRide(){
    struct tm nowLocal = getCurrentTime();
    char ct[80];
    strftime(ct,80,"%m-%d-%y %I:%M%p", &nowLocal);
    cout << endl;
    cout <<"Current time: "<< ct << endl;
    cout << endl;
    for(auto it = ridesVect.begin();it!=ridesVect.end();++it){

        if(((*it)->getPickUpHr()+1) == getCurrentTime().tm_hour){
            (*it)->setRideStatus("Completed");
            ((*it)->getDriver())->setIsAvailable(true);
            cout << ((*it)->getDriver())->getName() << " is now available!" << endl;
        } else {
            cout << ((*it)->getDriver())->getName() << " is not available for rides at the moment" << endl;
        }
    }

     
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
    string pLoc,dLoc;
    string rStat = "Active";
    int pCount;

    cout <<"How many passengers total?" << endl;
    cin >> pCount;

    bool hasPassedCheck = compBool(pObj, dObj,pCount);

    if(hasPassedCheck == true){
        //Instantiate object with pickup location, time, pCount, and rStat
        cout << "Enter the pickup location." << endl;
        cin.ignore(); getline(cin,pLoc);
        cout << "Enter the drop off location. " << endl;
        getline(cin,dLoc);

        incRideCount();
        temp = new Ride(pLoc,dLoc,rStat,(rideCount + 100000), pCount);
        temp->setDriver(dObj);
        temp->setPassenger(pObj);
        
        cout << "Ride pickup time is: " << endl;
        temp->setPickUpTime(temp->setTimeVal());
        
        cout <<(temp->getPickUpTime())<< endl;

        //Change drivers isavailable to false
        temp->getDriver()->setIsAvailable(false);
        //Push the temp into the rides vector
        ridesVect.push_back(temp);
    } else{
        cout << "Ride cannot be created" << endl;
    }
}
void Rides::printRides(){
    for(auto it = ridesVect.begin(); it != ridesVect.end(); ++it){
        cout << "Ride: " << endl;
        cout << "Ride ID: (R)" << (*it)->getRideID() << endl;
        cout << "Ride Status: " << (*it)->getRideStatus() << endl;
        cout << "Party Size: " << (*it)->getPartySize()<< endl;
        cout << "Pick up Location: " << (*it)->getPickUpLocation()<< endl;
        cout << "Drop off Location: " << (*it)->getDropOffLocation() << endl;
        cout << "Pick up Time and Date: " << (*it)->getPickUpTime()<< endl;
        cout << "Drop off Time and Date: " <<(*it)->getDropOffTime()<< endl << endl;
    }
}
Ride* Rides::findRide(int id){
    Ride* temp;
    
    for(auto it =ridesVect.begin();it!=ridesVect.end();++it){
        if((*it)->getRideID() == id){
            temp = *it;
        }
    }
    return temp;
}
void Rides::editRide(int id){
    int choice = -1;
    string pLoc, dLoc;
    Ride* temp = findRide(id);

    while(choice == -1 || choice != 0){
        cout << "Enter what to edit for Passenger:" << endl;
        cout << "0- Back 1- Pick up Location 2- Drop off Location" << endl;
        cin >> choice;

        switch (choice){
            case 0:
                //Break switch
            break;
            case 1:
            cout << "Enter new name for passenger." << endl;
            cin >> pLoc;
            temp->setPickUpLocation(pLoc);
            break;
            case 2:
            cout <<"Enter a new Payment Preference (cash or card)" << endl;
            cin >> dLoc;
            temp->setDropOffLocation(dLoc);
            break;
            default:

            break;
        }
    }
}
void Rides::cancelRide(int id){
    Ride* temp = findRide(id);
    unsigned int i;

    for(i=0;i<ridesVect.size();i++){
        if((ridesVect.at(i))->getRideID() == id){
            (ridesVect.at(i))->getDriver()->setIsAvailable(true);
            (ridesVect.at(i))->setRideStatus("Cancelled");
            ridesVect.erase(ridesVect.begin() + i);
            decRideCount();
            //Consider a vector of cancelled rides
        }
    }
    delete temp;
    cout << "Ride Cancelled." << endl;
}

//Load Rides from file
void Rides::loadRides(vector<Passenger*>pVect,vector<Driver*> dVect){
    ifstream fin;
    //Variables to fin
    string pLoc, dLoc, rStat;
    float cRating;
    bool isAvail, allowHandicap, allowPets;
    int rId, pSize, dId, pId;
    string pTime, dTime;
    //Create passengers and drivers objects with input vectors
    Passengers pObj(pVect);
    Drivers dObj(dVect);
    
    //Open data file named Drivers.dat
    fin.open("Rides.dat");
    //Input for passenger count fin.ignore() ignores the newline
    fin >> rideCount; fin.ignore();
    //Input and push loaded data into the vector
    for(int i=0;i<rideCount;i++){
        getline(fin,pLoc);
        getline(fin,dLoc);
        fin >>cRating>> rStat >> rId >> pSize;
        fin.ignore(); getline(fin, pTime);
        getline(fin, dTime);
        fin >> dId >> pId; fin.ignore();
        //Pushes new ride object pointer into the rides vector
        Ride* rTemp = new Ride(pLoc,rStat,rId,pSize, pTime, dTime);
        rTemp->setDriver(dObj.findDriver(dId));
        rTemp->setPassenger(pObj.findPassenger(pId));
        ridesVect.push_back(rTemp);
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
        fout <<temp->getPickUpLocation() << "\n" << temp->getDropOffLocation()<< "\n" << temp->getCustRating()<< " " << temp->getRideStatus()<< " " << temp->getRideID()<< " " << temp->getPartySize()<< "\n"<< temp->getPickUpTime() << "\n" << temp->getDropOffTime() << "\n";
        fout <<(temp->getDriver())->getdID()<< " " <<(temp->getPassenger())->getpID() << endl;
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
