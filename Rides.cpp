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
    char ct[80];
    strftime(ct,80,"%m-%d-%y %I:%M%p", &nowLocal);
    return nowLocal;

}
//Complete rides if an hour(assumed value) has passed
void Rides::completeRide(){
    float ratingInp;
    struct tm nowLocal = getCurrentTime();
    char ct[80];
    strftime(ct,80,"%m-%d-%y %I:%M%p", &nowLocal);
    cout << endl;
    cout <<"Current Time: "<< ct << endl;
    cout << endl;
    for(auto it = ridesVect.begin();it!=ridesVect.end();++it){
        //Check if more than an hour has passed (assumed value is an hour per ride)
        if(((((*it)->getPickUpHr()+1) > getCurrentTime().tm_hour && (*it)->getPickUpDay() < getCurrentTime().tm_mday)
        || (((*it)->getPickUpHr()+1) < getCurrentTime().tm_hour && (*it)->getPickUpDay() == getCurrentTime().tm_mday)) 
        && ((*it)->getRideStatus() == "Active")){
            //Make changes to ride and driver status
            (*it)->setRideStatus("Completed");
            //setisAvailable takes in a char
            ((*it)->getDriver())->setIsAvailable('y');
            (*it)->setDropOffTime(getCurrentTime());
            //Enter a rating for the ride
            cout << "Please enter a rating for the ride.(0-5)(decimals can be used)" << endl;
            cin >> ratingInp;
            (*it)->getDriver()->setDriverRating(ratingInp);
            //Print that a driver is now available
            cout << ((*it)->getDriver())->getName() << " is now available!" << endl;
        } else if((*it)->getRideStatus() == "Completed") {
            if((*it)->getRideStatus() == "Active" && (*it)->getDriver()->getIsAvailable() == false){
                cout << ((*it)->getDriver())->getName() << " is not available for rides at the moment" << endl;
            }

        }
    }

     
}
//Helper function to check boolean values from both Passenger and Driver 
bool Rides::compBool(Passenger* pObj, Driver* dObj, int pCount){
    bool returnVal;
    
    if(dObj->getDriverRating() >= pObj->getRatingRequirement()){
        //cout << "Driver meets passenger rating requirement." << endl;
        if(dObj->getIsAvailable() == true && dObj->getVehicleCap() >= pCount){
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
void Rides::createRide(Passenger* pObj, Driver* dObj){
    Ride* temp;
    string pLoc,dLoc;
    string rStat = "Active";
    int pCount;
    cout <<"How many passengers total?" << endl;
    cin >> pCount;

    bool hasPassedCheck = compBool(pObj, dObj,pCount);

    if(hasPassedCheck == true){
        if(pObj->getPaymentPref() == "Cash"){
            cout << endl;
            cout << "****All cash users must pay the estimated cost upfront with the driver!****" << endl;
            cout << endl;
        }
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
        dObj->setIsAvailable('n');
        temp->getDriver()->setIsAvailable('n');
        //Push the temp into the rides vector
        ridesVect.push_back(temp);
    } else{
        cout << "Ride cannot be created" << endl;
    }
}
void Rides::printRides(){
    int choice =-1;
    while(choice ==-1 || choice != 0){
        cout << "Please specify your search query: " << endl;
        cout << "0- Back 1- All 2- Active 3- Cancelled 4- Completed" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        cout << "All:" << endl << endl;
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
            break;
        case 2:
        cout << "Active:" << endl << endl;
            for(auto it = ridesVect.begin(); it != ridesVect.end(); ++it){
                if((*it)->getRideStatus() == "Active"){
                    cout << "Ride: " << endl;
                    cout << "Ride ID: (R)" << (*it)->getRideID() << endl;
                    cout << "Ride Status: " << (*it)->getRideStatus() << endl;
                    cout << "Party Size: " << (*it)->getPartySize()<< endl;
                    cout << "Pick up Location: " << (*it)->getPickUpLocation()<< endl;
                    cout << "Drop off Location: " << (*it)->getDropOffLocation() << endl;
                    cout << "Pick up Time and Date: " << (*it)->getPickUpTime()<< endl;
                    cout << "Drop off Time and Date: " <<(*it)->getDropOffTime()<< endl << endl;
                } else if(it == ridesVect.end()-1) {
                    cout << "None available" << endl << endl;
                }
            }
        break;
        case 3:
        cout << "Cancelled:" << endl << endl;
            for(auto it = ridesVect.begin(); it != ridesVect.end(); ++it){
                if((*it)->getRideStatus() == "Cancelled"){
                    cout << "Ride: " << endl;
                    cout << "Ride ID: (R)" << (*it)->getRideID() << endl;
                    cout << "Ride Status: " << (*it)->getRideStatus() << endl;
                    cout << "Party Size: " << (*it)->getPartySize()<< endl;
                    cout << "Pick up Location: " << (*it)->getPickUpLocation()<< endl;
                    cout << "Drop off Location: " << (*it)->getDropOffLocation() << endl;
                    cout << "Pick up Time and Date: " << (*it)->getPickUpTime()<< endl;
                    cout << "Drop off Time and Date: " <<(*it)->getDropOffTime()<< endl << endl;
                } else if(it == ridesVect.end()-1) {
                    cout << "None available" << endl << endl;
                }
            }
        break;
        case 4:
        cout << "Completed:" << endl << endl;
            for(auto it = ridesVect.begin(); it != ridesVect.end(); ++it){
                if((*it)->getRideStatus() == "Completed"){
                    cout << "Ride: " << endl;
                    cout << "Ride ID: (R)" << (*it)->getRideID() << endl;
                    cout << "Ride Status: " << (*it)->getRideStatus() << endl;
                    cout << "Party Size: " << (*it)->getPartySize()<< endl;
                    cout << "Pick up Location: " << (*it)->getPickUpLocation()<< endl;
                    cout << "Drop off Location: " << (*it)->getDropOffLocation() << endl;
                    cout << "Pick up Time and Date: " << (*it)->getPickUpTime()<< endl;
                    cout << "Drop off Time and Date: " <<(*it)->getDropOffTime()<< endl << endl;
                } else if(it == ridesVect.end()-1) {
                    cout << "None available" << endl << endl;
                }
            }
        break;
        
        default:
        
        break;
        }
    }
}
void Rides::printRidesByDriver(int id){
    for(auto it = ridesVect.begin(); it != ridesVect.end(); ++it){
        if((*it)->getDriver()->getdID() == id){
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
//Edit Ride by changing the pickup and drop off location
void Rides::editRide(int id){
    int choice = -1;
    string pLoc, dLoc;
    Ride* temp = findRide(id);

    while(choice == -1 || choice != 0){
        cout << "Enter what to edit for Ride:" << endl;
        cout << "0- Back 1- Pick up Location 2- Drop off Location" << endl;
        cin >> choice;

        switch (choice){
            case 0:
                //Break switch
            break;
            case 1:
            cout << "Enter new pickup location for Ride." << endl;
            getline(cin,pLoc);
            temp->setPickUpLocation(pLoc);
            break;
            case 2:
            cout <<"Enter a new drop off location" << endl;
            cin.ignore();getline(cin, dLoc);
            temp->setDropOffLocation(dLoc);
            break;
            default:

            break;
        }
    }
}
void Rides::cancelRide(int id){
    Ride* temp = findRide(id);

    for(auto it = ridesVect.begin(); it!=ridesVect.end();++it){
        //Create an if statement to ensure that the only active ride with the matched ID gets cancelled
        if((*it)->getRideStatus() =="Active" && (*it)->getRideID()==temp->getRideID()){
            temp->setRideStatus("Cancelled");
            temp->getDriver()->setIsAvailable('y');
            cout << endl;
            cout << "Ride has been Cancelled."<< endl << endl;
        }

    }

}

//Load Rides from file
void Rides::loadRides(vector<Passenger*>pVect,vector<Driver*> dVect){
    ifstream fin;
    //Variables to fin
    string pLoc, dLoc, rStat;
    bool isAvail, allowHandicap, allowPets;
    int rId, pSize, dId, pId, pUHr, pUDay;
    string pTime, dTime;
    //Create passengers and drivers objects with input vectors
    Passengers pObj(pVect);
    Drivers dObj(dVect);
    
    //Open data file named Rides.dat
    fin.open("Rides.dat");
    //Input for passenger count fin.ignore() ignores the newline
    fin >> rideCount; fin.ignore();
    //Input and push loaded data into the vector
    for(int i=0;i<rideCount;i++){
        getline(fin,pLoc);
        getline(fin,dLoc);
        fin >> rStat >> rId >> pSize;
        fin.ignore(); getline(fin, pTime);
        getline(fin, dTime);
        fin >> dId >> pId >> pUHr >> pUDay; fin.ignore();
        //Pushes new ride object pointer into the rides vector
        Ride* rTemp = new Ride(pLoc,dLoc,rStat,rId,pSize, pTime, dTime,pUHr,pUDay);
        rTemp->setDriver(dObj.findDriver(dId));
        rTemp->setPassenger(pObj.findPassenger(pId));
        ridesVect.push_back(rTemp);
    }
    //Close file
    fin.close();
}
void Rides::saveRides(){
    ofstream fout;
    //Open Rides.dat
    fout.open("Rides.dat");
    //Save rideCount into the file
    fout << rideCount << endl;
    Ride* temp;

    //Use iterator for iterating through the vector
    for(auto it = ridesVect.begin(); it != ridesVect.end(); ++it){
        //temp becomes the passenger pointer that it points to
        temp = *it;
        //Saves all the variable data in order of object instanciation
        fout <<temp->getPickUpLocation() << "\n" << temp->getDropOffLocation()<< "\n" << temp->getRideStatus()<< " " << temp->getRideID()<< " " << temp->getPartySize()<< "\n"<< temp->getPickUpTime() << "\n" << temp->getDropOffTime() << "\n";
        fout <<(temp->getDriver())->getdID()<< " " <<(temp->getPassenger())->getpID()<<" "<<temp->getPickUpHr() <<" "<<temp->getPickUpDay()<< endl;
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
