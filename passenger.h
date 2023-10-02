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
    void setPassId(int pID);
    void setRatingReq(float ratReq);
    void setHasPets(bool hPets);
    void setIsHandicap(bool isHandi);
    //Getters
    string getName() const {return name;}
    string getPaymentPref() const {return paymentPref;}
    int getPassID() const {return passId;}
    float getRatingRequirement() const {return ratingRequirement;}
    bool getHasPets() const {return hasPets;}
    bool getIsHandicap() const {return isHandicap;}

    private:
    string name;
    string paymentPref;
    int passID;
    float ratingRequirement;
    bool hasPets;
    bool isHandicap;

}
#endif