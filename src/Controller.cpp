#include <vector>

#include "Controller.h"

Controller::Controller() {
}

Controller::Controller(const Controller& orig) {
}

Controller::~Controller() {
}

void Controller::setup(float timesPerSecond) {

    //setup hid pressure pen interface & try to open default device
    hidpen::setup();

    setAddress("localhost", 9997, 9998);
    Sessio::setup(300, 200);
    timedThread::setup(timesPerSecond);
    piirto::setup(ofGetWidth(), ofGetHeight());

}

void Controller::update() {
    Sessio::update();
    
    //lähetetään randomlukuja erikoisosoitteeseen testailua varten
    if(connection)
        sendFloat("/debug", ofRandom(1));
        
    //päivitetään kynän painetieto hidpeniin.
    if(hidpen::update() ) {
        //jos luettiin jotain, se tarkoittaa että kynä on olemassa
        penExists = true;
    }

    
    //lähetetään kynästä tai hiirestä saadut tiedot
    if (Sessio::moodi == piirtaa) {
        
        if (penExists) {
            //päivitetään kynän tiedot (nopeus ja paine) piirtoon ja lähetetään ne OSC:lla
            piirto::update(viivanHallinta.nopeus, 1 - hidpen::pressure, true);
            sendFloat("/nopeus", viivanHallinta.nopeus);
            sendFloat("/paine", hidpen::pressure );
        } else {
            //päivitetään hiiren tiedot (nopeus) piirtoon ja lähetetään ne OSC:lla
            piirto::update(viivanHallinta.nopeus, viivanHallinta.herkkyys, true);
            sendFloat("/nopeus", viivanHallinta.nopeus);
        }
    } else {
        double pi = 3.1415926535897;
        float arvo = sin((float) (Sessio::updateCount % 2000) / 2000 * pi);

        piirto::update(arvo, 1, false);
    }
}

void Controller::loop() {
    switch (Sessio::moodi) {
        case kalibroi:
            viivanHallinta.lisaaPisteKalibrointiin(hiiri.mouseState);
            if(penExists)
                viivanHallinta.lisaaHerkkyysKalibrointiin(1 - hidpen::pressure);
            viivanHallinta.kalibroi();
            piirto::tallennaAloitusVari();
            break;
        case piirtaa:
            viivanHallinta.lisaaPisteViivaan(hiiri.mouseState);
            if(penExists)
                viivanHallinta.lisaaHerkkyysViivaan(1 - hidpen::pressure);
            viivanHallinta.laskeJaVertaa();
            break;
        case viivaKesken:
            break;
        case viivaValmis:
            viivanHallinta.tyhjenna();
            break;
    }
}

void Controller::resize(int w_, int h_) {
    w = w_;
    h = h_;
    piirto::setup(w, h);
}