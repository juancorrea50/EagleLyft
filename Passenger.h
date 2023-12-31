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
    void setHasPets(char inVal);
    void setIsHandicap(char inVal);
    //Getters
    string getName() const {return name;}
    string getPaymentPref() const;
    float getRatingRequirement() const {return ratingRequirement;}
    bool getHasPets() const {return hasPets;}
    bool getIsHandicap() const {return isHandicap;}
    int getpID() const {return pID;}
    //Operator overload of the extractor and insertion operators
    friend ostream& operator<<(ostream& fout, const Passenger& p);
    friend istream& operator>>(istream& fin, Passenger& p);


    private:
    string name;
    pPref paymentPref;
    int pID;
    float ratingRequirement;
    bool hasPets;
    bool isHandicap;

};

#endif