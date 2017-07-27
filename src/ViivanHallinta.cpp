
#include <vector>

#include "ViivanHallinta.h"
#include "Controller.h"

float SigmoidFunction(float value) {
    
    return 1 / (1 + exp(-value));
    
}

void ViivanHallinta::laskeJaVertaa() {
    
    viiva.laskeKeskinopeus();
    
    float maksimiNopeus = 1;
    
    nopeus = (viiva.keskinopeus-kalibrointi.keskinopeus) / maksimiNopeus;
    nopeus = SigmoidFunction(nopeus);
}

void ViivanHallinta::lisaaPisteKalibrointiin(ofPoint piste) {
    kalibrointi.pisteet.push_back(piste);
}

void ViivanHallinta::lisaaPisteViivaan(ofPoint piste) {
    viiva.pisteet.push_back(piste);
}

void ViivanHallinta::kalibroi() {
    kalibrointi.laskeKeskinopeus();
}

void ViivanHallinta::tyhjenna() {
    kalibrointi.pisteet.clear();
    viiva.pisteet.clear();
}