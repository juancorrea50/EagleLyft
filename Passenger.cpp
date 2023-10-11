#include <string>
#include "Passenger.h"


using namespace std;

    Passenger::Passenger(){
        name = "none";
        paymentPref = cash;
        pID = 100000;
        ratingRequirement = 0.00;
        hasPets = false;
        isHandicap = false;
    }
    Passenger::Passenger(string n, pPref pPref, int passID, float rateReq, bool hPets, bool isHandi) {
        name = n;
        paymentPref = pPref;
        ratingRequirement = rateReq;
        pID = passID;
        hasPets = hPets;
        isHandicap = isHandi;
    }
    //Getters defined in header file

    //Getter for payment preference
    string Passenger::getPaymentPref() const{
        if(paymentPref == card){
            return "Card";
        } else if(paymentPref == cash){
            return "Cash";
        } else {
            return "Not Chosen";
        }
    }

    //Setters
    void Passenger::setName(string nm){
        name = nm;
    }
    void Passenger::setPaymentPref(string pprf){
        if(pprf == "card"){
            paymentPref = card;
        } else if(pprf == "cash"){
            paymentPref = cash;
        }
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

