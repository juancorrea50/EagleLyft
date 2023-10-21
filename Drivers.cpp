#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include "Drivers.h"

using namespace std;
using namespace std;
//Constructors
Drivers::Drivers(){
    driverCount = 0;
}
Drivers::Drivers(vector<Driver *> dVect){
    driverVect = dVect;
}
int Drivers::incDriverCount(){
    driverCount++;
    return driverCount;
}

//Add Passenger to vector
void Drivers::addDriver(){
    string nm, vType, notes;
    float driverRating;
    bool isAvail, allowHandicap, allowPets;
    char isAv,aHandi, aPets;
    Driver* temp;

    cout << "Enter driver's name: " << endl;
    cin >> nm;
    cin.ignore();


    cout << "Enter vehicle type (SUV,Sedan, Coupe)" << endl;
    cin >> vType;
    cin.ignore();
    //Create code to make the string all lower case

    //Have customer set the rating

    cout << "Enter if you are available right now (y or n)" << endl;
    cin >> isAv;
    if((char)tolower(isAv) == 'y'){
        isAvail = true;
    } else if((char)tolower(isAv) == 'n'){
        isAvail = false;
    }


    cout << "Is your vehicle handicap accessable? (y or n)" << endl;
    cin >> aHandi;

    if((char)tolower(aHandi) == 'y'){
        allowHandicap = true;
    } else if(tolower(aHandi) == 'n'){
        allowHandicap = false;
    }

    cout << "Do you have pets for your trips? (y/n)" << endl;
    cin >> aPets;
    cin.ignore();
    if((char)tolower(aPets) == 'y'){
        allowPets = true;
    } else if((char)tolower(aPets) == 'n'){
        allowPets = false;
    }
    cout << "Enter any notes about the driver: " << endl;
    getline(cin, notes);
    //cin.ignore();

    //Increment Passenger count
    incDriverCount();
    
    //Create temp object in memory and push a new object pointer that uses driverCount+100000 to create a unique ID number for driver's ID
    temp = new Driver(nm, vType, notes,(driverCount+100000), isAvail, allowPets, allowHandicap);
    driverVect.push_back(temp);
}
//Print Drivers Vector
void Drivers::printDrivers(){
    unsigned int i;
    char iHandi;
    char hPets, isAv;
    for(i=0;i<driverVect.size();i++){
        isAv = (driverVect.at(i)->getIsAvailable() == true) ? 'Y' : 'N';
        iHandi = (driverVect.at(i)->getHandicapAvail() == true) ? 'Y' : 'N';
        hPets = (driverVect.at(i)->getAllowPets() == true) ? 'Y' : 'N';
        
        cout <<"Driver: " <<endl;
        cout << "Name: " << driverVect.at(i)->getName() << endl;
        cout << "ID: (D)" << driverVect.at(i)->getdID() << endl;
        cout << "Vehicle Type: " << driverVect.at(i)->getVehicleType() << endl;
        cout << "With a cap of: " << driverVect.at(i)->getVehicleCap() << endl;
        cout << "Is Available: " << isAv << endl;
        cout << "Handicap Capable: " << iHandi << endl;
        cout << "Allows Pets: " << hPets<< endl;
        cout << "Notes: " << driverVect.at(i)->getNotes() << endl;
        cout << endl;
    }
}
//Load Drivers from file
void Drivers::loadDrivers(){
    ifstream fin;
    //Variables to fin
    string nm, vType, notes;
    float driverRating;
    bool isAvail, allowHandicap, allowPets;
    //char isAv,aHandi, aPets;
    unsigned long int id;
    
    //Open data file named Drivers.dat
    fin.open("Drivers.dat");
    //Input for passenger count fin.ignore() ignores the newline
    fin >> driverCount; fin.ignore();
    //Input and push loaded data into the vector
    for(int i=0;i<driverCount;i++){
        fin >> nm >> vType;
        fin.ignore(); getline(fin,notes);
        fin >> id;
        fin >> isAvail >> allowPets>> allowHandicap;
        driverVect.push_back(new Driver(nm,vType,notes,id,isAvail,allowPets,allowHandicap));
    }
    //Close file
    fin.close();
}
void Drivers::saveDrivers(){
    ofstream fout;
    //Save driverCount into the file
    fout.open("Drivers.dat");
    fout << driverCount << endl;
    Driver* temp;

    //Use iterator for iterating through the vector
    for(auto it = driverVect.begin(); it != driverVect.end(); ++it){
        //temp becomes the passenger pointer that it points to
        temp = *it;
        //Saves all the variable data in order of object instanciation
        fout << temp->getName() << " " << temp->getVehicleType()<< "\n" << temp->getNotes()<< "\n" << temp->getdID()<< "\n" << temp->getIsAvailable()<< " " << temp->getAllowPets() << " "<< temp->getHandicapAvail() << "\n";
    }
    //close output file
    fout.close();
}
//Edit design to include this function
Driver* Drivers::findDriver(int id){
    unsigned int i;
    Driver* temp;
    
    for(i=0;i<driverVect.size();i++){
        if(driverVect.at(i)->getdID() == id){
            temp = driverVect.at(i);
        }
    }
    return temp;
}
void Drivers::editDriver(int id){
    int choice = -1;
    string nm, vType, notes;
    float driverRating;
    bool isAvail, allowHandicap, allowPets;
    char isAv,aHandi, aPets;
    Driver* temp = findDriver(id);


    while(choice == -1 || choice != 0){
        cout << "Enter what to edit for Passenger:" << endl;
        cout << "0- Back 1- Name 2- Vehicle Type 3- Notes 4- Available 5- Allow Pets 6- Handicap Available " << endl;
        cin >> choice;

        switch (choice){
            case 0:
                //Break switch
            break;
            case 1:
            cout << "Enter new name for driver." << endl;
            cin >> nm;
            temp->setName(nm);
            break;
            case 2:
            cout <<"Enter a new Vehicle Type (suv, sedan, coupe)" << endl;
            cin >> vType;
            temp->setVehicleType(vType);
            break;
            case 3:
            cout << "Enter new notes (will replace old notes)" << endl;
            cin.ignore();
            getline(cin, notes);
            temp->setNotes(notes);
            break;
            case 4:
            cout << "Are you still available(y/n)?" << endl;
            cin >> isAv;
            temp->setIsAvailable(isAv);
            break;
            case 5:
            cout << "Are pets still allowed (y/n)?" << endl;
            cin >> aPets;
            temp->setAllowPets(aPets);
            break;
            case 6:
            cout << "Is your vehicle still handicap capable(y/n)?" << endl;
            cin >> aHandi;
            temp->setHandicapAvail(aHandi);
            break;
            default:

            break;
        }
    }
}
void Drivers::deleteDriver(int id){
    Driver* temp = findDriver(id);
    unsigned int i;
    for(i=0;i<driverVect.size();i++){
        if(driverVect.at(i)->getdID() == id){
            driverVect.erase(driverVect.begin() + i);
            decDriverCount();
        }
    }
    delete temp;
    cout << "Driver Deleted." << endl << endl;
}
void Drivers::cleanUp(){
    for(auto it = driverVect.begin(); it!= driverVect.end(); ++it){
        delete *it;
    }
    driverVect.clear();
    driverCount = 0;
}