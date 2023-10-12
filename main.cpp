#include <iostream>
#include <string>
#include "Passenger.h"
#include "Passengers.h"
using namespace std;

Passengers passengers;

int main(){
    int choice =-1;
    int editChoice = -1;
    //Will use for input when tasked to delete
    int id = 0;

    //Load file
    passengers.loadPassengers();

    while(choice == -1 || choice != 0){
        cout << "Welcome to EagleLyft:" << endl;
        cout << "0- Quit 1- Add Driver 2- Add Passenger 3- Add Ride 4- Print Passengers 5- Print Drivers " << endl;
        cout << "6- Print Rides 7- Delete Passenger 8- Delete Ride 9- Delete Driver 10- Edit" << endl;
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
            //Print passenger vector
            passengers.printPassengers();
            break;
            case 10:
            //Edit one of the 3 choices
                while(editChoice == -1 || editChoice > 3 || editChoice != 0 || editChoice < 0){
                cout << "Would you like to edit a 1- Passenger 2- driver or 3- ride? (Enter 0 to quit)" << endl;
                cin >> editChoice;
                    switch (editChoice){
                    case 1:
                        cout << "Enter the id of the passenger you would like to edit" << endl;
                        cin >> id;
                        passengers.editPassenger(id);
                    break;
                    
                    default:
                    
                    break;
                    }
                }
            case 7:
            //Delete passenger
            cout << "Enter id to delete passenger" << endl;
            cin >> id;
            passengers.deletePassenger(id);
            break;
            break;
            default:
            cout << "Switch skipped" << endl;
        }

    }
    passengers.savePassengers();
    passengers.cleanUp();
    
    return 0;
}