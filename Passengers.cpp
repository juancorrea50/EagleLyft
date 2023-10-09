#include <iostream>
#include <string>
#include <vector>
#include "Passengers.h"


using namespace std;
//Constructors
Passengers::Passengers(){
    passengerCount = 0;
    pID = 100000;
}
Passengers::Passengers(vector<Passenger*> pVect){
    passVector = pVect;
    passengerCount++;
    pID = 100000;
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
        
        if((char)tolower(hPets) == 'y'){
            hsPets = true;
        } else if((char)tolower(hPets) == 'n'){
            hsPets = false;
        }
    }while((char)tolower(hPets) != 'n' && (char)tolower(hPets) != 'y');

    temp = new Passenger(n, pPref, ratReq, isHC, hsPets);
    incPassId();
    passengerCount++;
    ///*
    cout << n << " " << pPref <<" " << ratReq << " " << isHC << " " << hsPets << endl;
    //*/
    passVector.push_back(temp);
}
//Print Passenger from pointer
void Passengers::printPassengers(){
    unsigned int i;
    char iHandi;
    char hPets;
    for(i=0;i<passVector.size();i++){
        iHandi = ((passVector.at(i))->getIsHandicap() == true) ? 'Y' : 'N';
        hPets = ((passVector.at(i))->getHasPets() == true) ? 'Y' : 'N';
        cout << "Name: " << (passVector.at(i))->getName() << endl;
        cout << "ID: " << getpID() << endl;
        cout << "Payment Preference: " << (passVector.at(i))->getPaymentPref() << endl;
        cout << "Rating Requirement: " << (passVector.at(i))->getRatingRequirement() << endl;
        cout << "Handicap: " << iHandi << endl;
        cout << "Pets: " << hPets<< endl;
    }
    cout << "Passenger Total: " << passengerCount << endl;
    
     


}