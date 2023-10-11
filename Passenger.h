#ifndef PASSENGER_H
#define PASSENGER_H
#include <string>

using namespace std;

enum pPref{card, cash};
class Passenger{
    public:
    //Default Contructor
    Passenger();
    //Param Constructor
    Passenger(string n, pPref pPref,int passID, float rateReq, bool hPets, bool isHandi);
    //Setters
    void setName(string nm);
    void setPaymentPref(string pprf);
    void setRatingReq(float ratReq);
    void setHasPets(bool hPets);
    void setIsHandicap(bool isHandi);
    //Getters
    string getName() const {return name;}
    string getPaymentPref() const;
    float getRatingRequirement() const {return ratingRequirement;}
    bool getHasPets() const {return hasPets;}
    bool getIsHandicap() const {return isHandicap;}
    int getpID() const {return pID;}


    private:
    string name;
    pPref paymentPref;
    int pID = 100000;
    float ratingRequirement;
    bool hasPets;
    bool isHandicap;

};
#endif