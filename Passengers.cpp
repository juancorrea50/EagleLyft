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
    int id;
    float ratReq;
    bool isHC, hsPets;
    char iHandi, hPets;
    Passenger* temp;

    cout << "Enter your(passenger's) name: " << endl;
    cin >> n;
    cin.ignore();

    cout << "Enter passenger's id: " << endl;
    cin >> id;
    cin.ignore();

    cout << "Enter payment preference: " << endl;
    cin >> pPref;
    cin.ignore();

    cout << "Enter rating requirement for driver: " << endl;
    cin >> ratReq;
    cin.ignore();

    //While loops to ensure usable answer for boolean values
    while(tolower(iHandi) != 'n' || tolower(iHandi) != 'y'){
        cout << "Are you in need of a handicap vehicle?" << endl;
        cin >> iHandi;
        cin.ignore();
        if(tolower(iHandi) == 'y'){
            isHC = true;
        } else if(tolower(iHandi) == 'n'){
            isHC = false;
        }
    }
    while(tolower(hPets) != 'n' || tolower(hPets) != 'y'){
        cout << "Do you have pets for your trips?" << endl;
        cin >> hPets;
        if(tolower(hPets) == 'y'){
            hsPets = true;
        } else if(tolower(hPets) == 'n'){
            hsPets = false;
        }
    }

    temp = new Passenger(n, pPref, id, ratReq, isHC, hsPets);
    passVector.push_back(temp);
    delete temp;

}