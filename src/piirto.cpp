#include "piirto.h"

ofColor ofRandomColor() {
	return ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
}


piirto::piirto()
{
}

piirto::~piirto()
{
}

void piirto::setup(int w_, int h_) {
	w = w_;
	h = w_;
        pehmennettyNopeus = 0;
}

void piirto::update(float nopeus) {
    pehmennettyNopeus = pehmennettyNopeus * 0.9 + nopeus * 0.1;
    colorBuffer = ofColor(ofMap(pehmennettyNopeus,0,1,0,255));
}

void piirto::draw() {
	ofSetColor(colorBuffer);
	ofDrawRectangle(0,0,w,h);
}

