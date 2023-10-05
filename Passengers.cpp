#include <iostream>
#include <string>
#include <map>
#include "Passengers.h"


using namespace std;

Passengers::Passengers(){
    passengerCount = 0;
}

Passengers::Passengers(vector<Passenger> pVect, int pCount){
    passVector = pVect;
    passengerCount = pCount;
}
void Passengers::addPassenger() const{
    string n, pPref;
    int id;
    float ratReq;
    bool isHandi, hPets;
    Passenger* temp;

    cout << "Enter your(passenger's) name" << endl;
    cin >> n;
    cin.ignore();

    cout << "Enter passenger's id " << endl;
    cin >> id;
    cin.ignore();

    cout << "Enter payment preference" << endl;
    cin >> pPref;
    cin.ignore();

    cout << "Enter rating requirement for driver" << endl;
    cin >> ratReq;
    cin.ignore();

    cout << "Are you in need of a handicap vehicle?" << endl;
    cin >> isHandi;
    cin.ignore();

    cout << "Do you have pets for your trips?" << endl;
    cin >> hPets;
    




    cout << "Enter "

    

    temp = new Passenger()

}