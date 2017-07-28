#pragma once

#include "Viiva.h"

struct ViivanHallinta {

    Viiva kalibrointi;
    Viiva viiva;
    
    float nopeus, vivahteikkuus, herkkyys;
    
    void kalibroi();
    void laskeJaVertaa();
    
    void lisaaPisteKalibrointiin(ofPoint piste);
    void lisaaHerkkyysKalibrointiin(float herkkyys);
    void lisaaPisteViivaan(ofPoint piste);
    void lisaaHerkkyysViivaan(float herkkyys);
    
    void tyhjenna();
    
};
