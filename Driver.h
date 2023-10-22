#ifndef DRIVER_H
#define DRIVER_H
#include <string>

using namespace std;

class Driver{
    public:
    //Default Contructor
    Driver();
    //Param Constructor
    Driver(string nm, string vType, string ntes, unsigned long int drID, bool isAvail, bool aPets, bool handAvail);
    //Setters
    void setName(string nm);
    void setVehicleType(string vType);
    void setNotes(string nts);
    void setVehicleCap(int cap);
    void setDriverRating(float dRating);
    void setIsAvailable(char inVal);
    void setAllowPets(char inVal);
    void setHandicapAvail(char inVal);
    //Getters
    string getName() const {return name;}
    string getVehicleType() const {return vehicleType;}
    string getNotes() const {return notes;}
    int getVehicleCap() const {return vehicleCap;}
    int getdID() const {return dID;}
    float getDriverRating() const {return driverRating;}
    bool getIsAvailable() const {return isAvailable;}
    bool getAllowPets() const {return allowPets;}
    bool getHandicapAvail() const {return handicapAvail;}

    


    private:
    string name;
    string vehicleType;
    string notes;
    int vehicleCap;
    unsigned long int dID;
    float driverRating;
    bool isAvailable;
    bool allowPets;
    bool handicapAvail;
    int rideCount;

};

#endif