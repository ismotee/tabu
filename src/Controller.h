#pragma once

#include "Sessio.h"
#include "piirto.h"
#include "ofMain.h"
#include "timedThread.h"
#include "ViivanHallinta.h"
#include "OscInterface.h"
#include "hidpen.h"


/* Controlller Class 
 *  Controller class stiches (Sessio, piirto, Hiiri) classes together. Controller class makes sure that
 *  everything happens in a fasionable order. Loop method runs in a separate thread, other functions are strictly timed (and named) 
 *  by the openframeworks ofApp functions.
 *
 */



class Controller: public Sessio, public piirto, public timedThread, public OscInterface {
public:
    bool penExists = false;
    ofTimer timer;
    ViivanHallinta viivanHallinta;
    
    Controller();
    Controller(const Controller& orig);
    virtual ~Controller();
    
    void setup(float timesPerSecond);
    void update();
    
    void loop();
    void resize(int w, int h);
    
    
private:

};


