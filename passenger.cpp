#include <string>
#include "passenger.h"

using namespace std;

/*    //Default Contructor

    //Param Constructor

    //Setters

    
    string name;
    string paymentPref;
    int passID;
    float ratingRequirement;
    bool hasPets;
    bool isHandicap;
    
    */
    Passenger::Passenger(){
        name = "none";
        paymentPref = "notChosen";
        passID = 0;
        ratingRequirement = 0.00;
        hasPets = false;
        isHandicap = false;
    }
    Passenger::Passenger(string n, string pPref, int pID, float rateReq, bool hPets, bool isHandi) {
        name = n;
        paymentPref = pPref;
        passID = pID;
        ratingRequirement = rateReq;
        hasPets = hPets;
        isHandicap = isHandi;
    }
    void Passenger::setName(string nm){
        name = nm;
    }
    void Passenger::setPaymentPref(string pPref){
        paymentPref = pPref;
    }
    void Passenger::setPassId(int pID){
        passID = pID;
    }
    void Passenger::setRatingReq(float ratReq){
        ratingRequirement = ratReq;
    }
    void Passenger::setHasPets(bool hPets){
        hasPets = hPets;
    }
    void Passenger::setIsHandicap(bool isHandi){
        isHandicap = isHandi;
    }
