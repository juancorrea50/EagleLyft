#include <iostream>
#include <string>
#include <vector>
#include "Passengers.h"


using namespace std;
//Constructors
Passengers::Passengers(){
    passengerCount = 0;
}
Passengers::Passengers(vector<Passenger*> pVect){
    passVector = pVect;
    passengerCount++;
}
// Increment Passenger ID
void Passengers::incPassId(){
    pID++;
}
//Add Passenger to vector
void Passengers::addPassenger(){
    string n, pPref;
    float ratReq;
    bool isHC, hsPets;
    char iHandi, hPets;
    Passenger* temp;

    cout << "Enter your (passenger's) name: " << endl;
    cin >> n;
    cin.ignore();


    cout << "Enter payment preference (Card or Cash):" << endl;
    cin >> pPref;
    cin.ignore();

    cout << "Enter rating requirement for driver (Out of 5 stars): " << endl;
    cin >> ratReq;
    cin.ignore();

    //While loops to ensure usable answer for boolean values
    do{
        cout << "Are you in need of a handicap vehicle? (y/n)" << endl;
        cin >> iHandi;
        cin.ignore();
        if((char)tolower(iHandi) == 'y'){
            isHC = true;
            cout << iHandi << endl;
        } else if(tolower(iHandi) == 'n'){
            isHC = false;
        }
    }while((char)tolower(iHandi) != 'y' && (char)tolower(iHandi) != 'n');
    do{
        cout << "Do you have pets for your trips? (y/n)" << endl;
        cin >> hPets;
        cin.ignore();
        if((char)tolower(hPets) == 'y'){
            hsPets = true;
        } else if((char)tolower(hPets) == 'n'){
            hsPets = false;
        }
    }while((char)tolower(hPets) != 'n' && (char)tolower(hPets) != 'y');

    temp = new Passenger(n, pPref, ratReq, isHC, hsPets);
    incPassId();
    printPassenger(temp);
    passVector.push_back(temp);

    delete temp;
}
//Print Passenger from pointer
void Passengers::printPassenger(Passenger* temp){
    char iHandi = (temp->getIsHandicap() == true) ? 'Y' : 'N';
    char hPets = (temp->getHasPets() == true) ? 'Y' : 'N';

    cout << "Name: " << temp->getName() << endl;
    cout << "ID: " << getpID() << endl;
    cout << "Payment Preference: " << temp->getPaymentPref() << endl;
    cout << "Rating Requirement: " << temp->getRatingRequirement() << endl;
    cout << "Handicap: " << iHandi << endl;
    cout << "Pets: " << hPets<< endl;
}