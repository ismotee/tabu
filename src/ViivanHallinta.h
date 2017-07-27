#pragma once

#include "Viiva.h"

struct ViivanHallinta {

    Viiva kalibrointi;
    Viiva viiva;
    
    float nopeus, vivahteikkuus, herkkyys;
    
    void kalibroi();
    void laskeJaVertaa();
    
    void lisaaPisteKalibrointiin(ofPoint piste);
    void lisaaPisteViivaan(ofPoint piste);
    
    void tyhjenna();
    
};
