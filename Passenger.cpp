#include <string>
#include "Passenger.h"

using namespace std;

    Passenger::Passenger(){
        name = "none";
        paymentPref = "notChosen";
        pID = 100000;
        ratingRequirement = 0.00;
        hasPets = false;
        isHandicap = false;
    }
    Passenger::Passenger(string n, string pPref, int pId, float rateReq, bool hPets, bool isHandi) {
        name = n;
        paymentPref = pPref;
        pID = 100000 + pID;
        ratingRequirement = rateReq;
        hasPets = hPets;
        isHandicap = isHandi;
    }
    //Getters defined in header file

    //Setters
    void Passenger::setName(string nm){
        name = nm;
    }
    void Passenger::setPaymentPref(string pPref){
        paymentPref = pPref;
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
    void Passenger::setpID(int pId){
        pID += pId;
    }
