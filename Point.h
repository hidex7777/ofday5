#pragma once
#include "ofMain.h"

class Point
{
public:
	Point();
	~Point() {};
	void update();
	void draw();
	//ofVec3f getLocation();
	ofVec3f location;
private:
	void setTarget();
	ofVec3f target;
	float myr;
};