#include <iostream>
#include <string>
#include "Passenger.h"
#include "Passengers.h"
using namespace std;

Passengers passengers;

int main(){
    int choice =-1;
    //Will use for input when tasked to delete
    int id = 0;

    //Load file
    passengers.loadPassengers();

    while(choice == -1 || choice != 0){
        cout << "Welcome to EagleLyft:" << endl;
        cout << "0- Quit 1- Add Driver 2- Add Passenger 3- Add Ride 4- Print Passengers 5- Print Drivers " << endl;
        cout << "6- Print Rides 7- Delete Passenger 8- Delete Ride 9- Delete Driver" << endl;
        cout << "Please choose an option: " << endl;
        cin >> choice;
        
        switch(choice){
            case 0:
            //Quit option
            break;
            case 2:
            //Add Passenger
            passengers.addPassenger();
            break;
            case 4:
            passengers.printPassengers();
            break;
            default:
            cout << "Switch skipped" << endl;
        }

    }
    passengers.savePassengers();
    
    return 0;
}