#ifndef PASSENGER_H
#define PASSENGER_H
#include <string>

using namespace std;

class Passenger{
    public:
    //Default Contructor
    Passenger();
    //Param Constructor
    Passenger(string n, string pPref, int pId, float rateReq, bool hPets, bool isHandi);
    //Setters
    void setName(string nm);
    void setPaymentPref(string pPref);
    void setRatingReq(float ratReq);
    void setHasPets(bool hPets);
    void setIsHandicap(bool isHandi);
    //Getters
    string getName() const {return name;}
    string getPaymentPref() const {return paymentPref;}
    int getPassID() const {return passID;}
    float getRatingRequirement() const {return ratingRequirement;}
    bool getHasPets() const {return hasPets;}
    bool getIsHandicap() const {return isHandicap;}
    //Increment passenger ID
    void setPassId(int pId);
    private:
    string name;
    string paymentPref;
    int passID = 100000;
    float ratingRequirement;
    bool hasPets;
    bool isHandicap;

};
#endif