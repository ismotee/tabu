#include <vector>

#include "Controller.h"

Controller::Controller() {
}

Controller::Controller(const Controller& orig) {
}

Controller::~Controller() {
}

void Controller::setup(float timesPerSecond) {
    pen.setup();
    setAddress("localhost", 9997, 9998);
    Sessio::setup(300, 200);
    timedThread::setup(timesPerSecond);
    piirto::setup(ofGetWidth(), ofGetHeight());
    cout << "tahan" << "\n";
    pen.readPressure();
    cout << "asti" << "\n";
}

void Controller::update() {
    Sessio::update();
    pen.readPressure();
    if (Sessio::moodi == piirtaa) {
        piirto::update(viivanHallinta.nopeus,1-pen.pressure,true);
        sendFloat("/nopeus",viivanHallinta.nopeus);
    } else {
        double pi = 3.1415926535897;
        float arvo = sin((float) (Sessio::updateCount % 2000) / 2000 * pi);

        piirto::update(arvo,1,false);
    }
}

void Controller::loop() {
    switch (Sessio::moodi) {
        case kalibroi:
            viivanHallinta.lisaaPisteKalibrointiin(hiiri.mouseState);
            viivanHallinta.kalibroi();
            piirto::tallennaAloitusVari();
            break;
        case piirtaa:
            viivanHallinta.lisaaPisteViivaan(hiiri.mouseState);
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