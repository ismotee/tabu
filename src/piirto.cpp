#include "piirto.h"

ofColor ofRandomColor() {
    return ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
}

piirto::piirto() {
}

piirto::~piirto() {
}

void piirto::setup(int w_, int h_) {
    w = w_;
    h = w_;
    pehmennettyNopeus = 0;
    savy = 0.7;
    saturaatio = 1;
    kirkkaus = 1;
}

void piirto::tallennaAloitusVari() {
   aloitusVari = colorBuffer; 
}

void piirto::update(float nopeus, float herkkyys, bool piirtaa) {
    if (piirtaa)
        laskeSavy(nopeus,herkkyys);
    laskeSaturaatio(nopeus,herkkyys);
    laskeKirkkaus(nopeus,herkkyys);
    colorBuffer.setHsb(savy, saturaatio * 255, kirkkaus * 255);
}

void piirto::draw() {
    ofSetColor(colorBuffer);
    ofDrawRectangle(0, 0, w, h);
}

void piirto::laskeSavy(float nopeus, float herkkyys) {
    if (nopeus > 0.9) {
        savy = colorBuffer.getHue() *0.98 + ofColor(255,150,0).getHue() * 0.02;
    } else {
        savy = colorBuffer.getHue()* 0.98 + aloitusVari.getHue() *0.02;
    }
}

void piirto::laskeSaturaatio(float nopeus, float herkkyys) {
    saturaatio = saturaatio * 0.96 + nopeus * 0.02 + herkkyys *0.04;    
}

void piirto::laskeKirkkaus(float nopeus, float herkkyys) {
    if (nopeus < 0.2) {
        kirkkaus = kirkkaus * 0.97 + nopeus * 0.01 + herkkyys * 0.02;
    } else {
        kirkkaus = kirkkaus * 0.97 + herkkyys * 0.03;
    }
    

}