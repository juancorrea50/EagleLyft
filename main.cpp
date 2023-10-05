#include <iostream>
#include <string>
#include "Passenger.h"
#include "Passengers.h"
using namespace std;

Passengers passengers;

int main(){
    int id;
    int choice =-1;

    cout << "Welcome to EagleLyft" << endl << "Please Enter a choice :" << endl;
    cout << "0 - quit\n 1 - Add item\n 2 - Add customer\n 3 - Add order\n 4 - print customers\n 5 " << endl;
    cout << "- print items\n 6 - print orders\n 7 - delete customer\n 8 - delete order\n 9 - delete item" << endl;
    cin >> choice;

    switch(choice){
        case 1:
        passengers.addPassenger();
        break;
        default:
        cout << "Switch skipped" << endl;
    }


    return 0;
}