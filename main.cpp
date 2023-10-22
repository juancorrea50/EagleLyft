#include <iostream>
#include <string>
#include "Passengers.h"
#include "Drivers.h"
#include "Rides.h"
using namespace std;

Passengers passengers;
Drivers drivers;
Rides rides;

int main(){
    int choice =-1;
    int secondChoice = -1;
    //Will use for input when tasked to delete
    int id = 0;
    int id2 = 0;

    //Load files
    passengers.loadPassengers();
    drivers.loadDrivers();
    rides.loadRides(passengers.getPassVect(),drivers.getDriverVect());
    
    rides.completeRide();
    
    while(choice == -1 || choice != 0){
        cout << "Welcome to EagleLyft:" << endl;

        cout << endl;
        cout << "0- Quit 1- Add Driver 2- Add Passenger 3- Create Ride 4- Print Passengers 5- Print Drivers " << endl;
        cout << "6- Print Rides 7- Delete Passenger 8- Cancel Ride 9- Delete Driver 10- Edit" << endl;
        cout << "Please choose an option: " << endl;
        cin >> choice;
        
        switch(choice){
            case 0:
            //Quit option
            break;
            case 1:
            drivers.addDriver();
            break;
            case 2:
            //Add Passenger
            passengers.addPassenger();
            break;
            case 3:
            cout << "Please enter the Passenger's ID" << endl;
            cin >> id;
            cout << "Please enter the requested Driver's ID" << endl;
            cin >> id2;
            
            rides.createRide(passengers.findPassenger(id),drivers.findDriver(id2));
            break;
            case 4:
            //Print passenger vector
            passengers.printPassengers();
            break;
            case 5:
            drivers.printDrivers();
            break;
            case 6:
            rides.printRides();
            break;
            case 7:
            //Delete passenger
            cout << "Enter id to delete passenger" << endl;
            cin >> id;
            passengers.deletePassenger(id);
            break;
            case 8:
            cout << "Enter ride ID to cancel" << endl;
            cin >> id;
            rides.cancelRide(id);
            break;
            case 9:
            //Delete Driver
            cout << "Enter id to delete passenger" << endl;
            cin >> id;
            drivers.deleteDriver(id);
            break;
            case 10:
            //Edit one of the 3 choices
                while(secondChoice == -1 || secondChoice > 3 || secondChoice != 0 || secondChoice < 0){
                cout << "0- Back 1- Passenger 2- driver or 3- ride" << endl;
                cin >> secondChoice;
                    switch (secondChoice){
                    case 1:
                    //Passenger
                        cout << "Enter the id of the passenger you would like to edit" << endl;
                        cin >> id;
                        passengers.editPassenger(id);
                    break;
                    case 2:
                    //Driver
                        cout << "Enter the id of the driver you would like to edit" << endl;
                        cin >> id;
                        drivers.editDriver(id);
                    break;
                    
                    default:
                    
                    break;
                    }
                }
            break;

            default:
            cout << "Switch skipped" << endl;
        }

    }
    //Save functions
    passengers.savePassengers();
    passengers.cleanUp();
    drivers.saveDrivers();
    drivers.cleanUp();
    rides.saveRides();
    rides.cleanUp();

    return 0;
}