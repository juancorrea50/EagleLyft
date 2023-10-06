#include <iostream>
#include <string>
#include <vector>
#include "Passengers.h"


using namespace std;

Passengers::Passengers(){
    passengerCount = 0;
}

Passengers::Passengers(vector<Passenger*> pVect, int pCount){
    passVector = pVect;
    passengerCount = pCount;
}
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
    temp->incPassId();
    passVector.push_back(temp);
    cout << "Name: " << temp->getName() << endl;
    cout << "ID: " << temp->getpID() << endl;
    cout << "Payment Preference: " << temp->getPaymentPref() << endl;
    cout << "Rating Requirement: " << temp->getRatingRequirement() << endl;
    cout << "Handicap: " << (char)toupper(iHandi) << endl;
    cout << "Pets: " << (char)toupper(hPets) << endl;
    delete temp;

}