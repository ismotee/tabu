#pragma once

#include "ofMain.h"


struct Viiva {

    std::vector<ofPoint> pisteet;
    float keskinopeus,keskiherkkyys;
    
    
    void laskeKeskinopeus(int otanta);
    void laskeKeskiherkkyys(int otanta);
    
    
float bound(float val, float min, float max) {
    if(val > max)
        return max;
    else if (val < min)
        return min;
    return val;
}

};
