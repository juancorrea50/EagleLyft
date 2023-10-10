#include <iostream>
#include <string>
#include "Passenger.h"
#include "Passengers.h"
using namespace std;

Passengers passengers;

int main(){
    int choice =-1;



    while(choice == -1 || choice != 0){
        cout << "Welcome to EagleLyft:" << endl;
        cout << "0- Quit 1- Add item 2- Add customer 3- Add order 4- Print customers 5- Print items " << endl;
        cout << "6- Print orders 7- Delete customer 8- Delete order 9- Delete item" << endl;
        cout << "Please choose an option: " << endl;
        cin >> choice;
        
        switch(choice){
            case 0:
            //Quit option
            break;
            case 1:
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
    return 0;
}