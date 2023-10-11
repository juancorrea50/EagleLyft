#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include "Passengers.h"


using namespace std;
//Constructors
Passengers::Passengers(){
    passengerCount = 0;
}
Passengers::Passengers(vector<Passenger*> pVect){
    passVector = pVect;
}
int Passengers::incPassCount(){
    passengerCount++;
    return passengerCount;
}

//Add Passenger to vector
void Passengers::addPassenger(){
    string n, ppStr;
    pPref pprf;
    float ratReq;
    bool isHC, hsPets;
    char iHandi, hPets;
    Passenger* temp;

    cout << "Enter your (passenger's) name: " << endl;
    cin >> n;
    cin.ignore();


    cout << "Enter payment preference (card or cash):" << endl;
    cin >> ppStr;
    if(ppStr == "card"){
        pprf = card;
    } else if(ppStr == "cash"){
        pprf = cash;
    }
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
    //Increment Passenger count
    incPassCount();
    
    //Create temp object in memory and push a new object pointer that uses passengerCount+100000 to create a unique ID number for passenger's ID
    temp = new Passenger(n, pprf,(passengerCount+100000), ratReq, isHC, hsPets);
    passVector.push_back(temp);
}
//Print Passengers Vector
void Passengers::printPassengers(){
    unsigned int i;
    char iHandi;
    char hPets;
    for(i=0;i<passVector.size();i++){
        iHandi = (passVector.at(i)->getIsHandicap() == true) ? 'Y' : 'N';
        hPets = (passVector.at(i)->getHasPets() == true) ? 'Y' : 'N';
        
        cout << "Name: " << passVector.at(i)->getName() << endl;
        cout << "ID: " << passVector.at(i)->getpID() << endl;
        cout << "Payment Preference: " << passVector.at(i)->getPaymentPref() << endl;
        cout << "Rating Requirement: " << passVector.at(i)->getRatingRequirement() << endl;
        cout << "Handicap: " << iHandi << endl;
        cout << "Pets: " << hPets<< endl;
    }
}
//Load passengers from file
void Passengers::loadPassengers(){
    ifstream fin;
    //Variables to fin
    string n, ppStr;
    pPref pprf;
    float ratReq;
    bool isHC, hsPets;
    char iHandi, hPets;
    int id;
    
    //Open data file named passengers.dat
    fin.open("passengers.dat");
    //Input for passenger count fin.ignore() ignores the newline
    fin >> passengerCount; fin.ignore();
    //Input and push loaded data into the vector
    for(int i=0;i<passengerCount;i++){
        fin >> n >> ppStr >> id >> ratReq >> isHC >> hsPets;
        if(ppStr == "Cash"){
            pprf = cash;
        } else if(ppStr == "Card"){
            pprf = card;
        }
        passVector.push_back(new Passenger(n, pprf,id,ratReq,isHC,hsPets));

    }
    //Close file
    fin.close();
}
void Passengers::savePassengers(){
    ofstream fout;
    //Save passengerCount into the file
    fout.open("passengers.dat");
    fout << passengerCount << endl;
    Passenger* temp;

    //Use iterator for iterating through the vector
    for(auto it = passVector.begin(); it != passVector.end(); ++it){
        //temp becomes the passenger pointer that it points to
        temp = *it;
        //Saves all the variable data in order of object instanciation
        fout << temp->getName() <<" "<< temp->getPaymentPref()<< " " << temp->getpID()<< " " << temp->getRatingRequirement()<< " " << temp->getIsHandicap()<< " " << temp->getHasPets();
    }
    //close output file
    fout.close();
}