#pragma once

#include "ofMain.h"

class piirto
{
public:

	int w,h;
	ofColor colorBuffer, aloitusVari;
        float pehmennettyNopeus;
        float savy,saturaatio,kirkkaus;
	
	piirto();
	virtual ~piirto();
	void setup(int w_, int h_);
	void update(float nopeus,float herkkyys,bool piirtaa);
	void draw();
        void tallennaAloitusVari();
        
        
        void laskeSavy(float nopeus, float herkkyys);
        void laskeSaturaatio(float nopeus, float herkkyys);
        void laskeKirkkaus(float nopeus, float herkkyys);
};

