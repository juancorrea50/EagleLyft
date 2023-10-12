#ifndef PASSENGERS_H
#define PASSENGERS_H
#include <vector>
#include "Passenger.h"

using namespace std;

class Passengers{
    public:
    //Construcors
    Passengers();
    Passengers(vector<Passenger*> pVect);
    //Increment passenger ID
    int incPassCount();
    //Decrement pass count
    void decPassCount(){passengerCount--;}
    //Add Passenger 1st prio testing
    void addPassenger();
    //Print passVector
    void printPassengers();
    //Load in Passengers data file
    void loadPassengers();
    //Save Passengers into a data file
    void savePassengers();
    //Helper function to find a Passenger in the vector
    Passenger* findPassenger(int id);
    //Edit function 
    void editPassenger(int id);

    private:
    //Count of all passengers in vector
    int passengerCount;
    //Pointer vector
    vector<Passenger*> passVector;
};
#endif