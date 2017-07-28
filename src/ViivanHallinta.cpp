
#include <vector>

#include "ViivanHallinta.h"
#include "Controller.h"

float SigmoidFunction(float value) {
    
    return 1 / (1 + exp(-0.5*value));
    
}

void ViivanHallinta::laskeJaVertaa() {
    
    viiva.laskeKeskinopeus(70);
    viiva.laskeKeskiherkkyys(70);
    
    float maksimiNopeus = kalibrointi.keskinopeus*0.2;
    
    nopeus = (viiva.keskinopeus-kalibrointi.keskinopeus) / maksimiNopeus;
    herkkyys = viiva.keskiherkkyys-kalibrointi.keskiherkkyys;
    
    nopeus = SigmoidFunction(nopeus);
    herkkyys = SigmoidFunction(herkkyys);
}

void ViivanHallinta::lisaaPisteKalibrointiin(ofPoint piste) {
    kalibrointi.pisteet.push_back(piste);
}

void ViivanHallinta::lisaaHerkkyysKalibrointiin(float herkkyys) {
    kalibrointi.pisteet.back().z = herkkyys;
}

void ViivanHallinta::lisaaHerkkyysViivaan(float herkkyys) {
    viiva.pisteet.back().z = herkkyys;
}


void ViivanHallinta::lisaaPisteViivaan(ofPoint piste) {
    viiva.pisteet.push_back(piste);
}

void ViivanHallinta::kalibroi() {
    kalibrointi.laskeKeskinopeus(kalibrointi.pisteet.size());
    kalibrointi.laskeKeskiherkkyys(kalibrointi.pisteet.size());
}

void ViivanHallinta::tyhjenna() {
    kalibrointi.pisteet.clear();
    viiva.pisteet.clear();
}