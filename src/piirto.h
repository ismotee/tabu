#pragma once

#include "ofMain.h"

class piirto
{
public:

	int w,h;
	ofColor colorBuffer;
        float pehmennettyNopeus;
	
	piirto();
	virtual ~piirto();
	void setup(int w_, int h_);
	void update(float nopeus);
	void draw();
};

