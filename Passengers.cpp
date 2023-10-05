#include <iostream>
#include <string>
#include <map>
#include "Passengers.h"


using namespace std;

Passengers::Passengers(){
    passengerCount = 0;
}

Passengers::Passengers(vector<Passenger*> pVect, int pCount){
    passVector = pVect;
    passengerCount = pCount;
}
void Passengers::addPassenger() const{
    string n, pPref;
    int id;
    float ratReq;
    bool isHC, hsPets;
    string iHandi, hPets;
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
    while(tolower(iHandi) != "n" || tolower(iHandi) != "no" || tolower(iHandi) != "y" || tolower(iHandi) != "yes"){
        cout << "Are you in need of a handicap vehicle?" << endl;
        cin >> iHandi;
        cin.ignore();
        if(tolower(iHandi) == "y" || tolower(iHandi) == "yes"){
            isHC = true;
        } else if(tolower(iHandi) == "n" || tolower(iHandi) == "no"){
            isHC = false;
        }
    }
    while(tolower(hPets) != "n" || tolower(hPets) != "no" || tolower(hPets) != "y" || tolower(hPets) != "yes"){
        cout << "Do you have pets for your trips?" << endl;
        cin >> hPets;
        if(tolower(hPets) == "y" || tolower(hPets) = "yes"){
            hsPets = true;
        } else if(tolower(hPets) == "n" || tolower(hPets) == "no"){
            hsPets = false;
        }
    }

    temp = new Passenger(n, pPref, id, ratReq, isHC, hsPets);
    passVector.push_back(temp);
    delete temp;

}