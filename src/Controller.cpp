#include <vector>

#include "Controller.h"

Controller::Controller() {
}

Controller::Controller(const Controller& orig) {
}

Controller::~Controller() {
}

void Controller::setup(float timesPerSecond) {
    setAddress("localhost", 9997, 9998);
    Sessio::setup(300, 200);
    timedThread::setup(timesPerSecond);
    piirto::setup(ofGetWidth(), ofGetHeight());
}

void Controller::update() {
    Sessio::update();
    if (Sessio::moodi == piirtaa) {
        piirto::update(viivanHallinta.nopeus);
        sendFloat("/nopeus",viivanHallinta.nopeus);
    } else {
        double pi = 3.1415926535897;
        float arvo = sin((float) (Sessio::updateCount % 2000) / 2000 * pi);

        piirto::update(arvo);
    }
}

void Controller::loop() {
    switch (Sessio::moodi) {
        case kalibroi:
            viivanHallinta.lisaaPisteKalibrointiin(hiiri.mouseState);
            viivanHallinta.kalibroi();
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