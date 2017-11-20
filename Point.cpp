#include "Point.h"

Point::Point() {
	this->setTarget();
	this->location.set(this->target);
}
void Point::update() {
	if (ofGetFrameNum() % 120 == 0) {
		this->setTarget();
	}
	this->location.x += (this->target.x - this->location.x) * 0.5;
	this->location.y += (this->target.y - this->location.y) * 0.5;
	this->location.z += (this->target.z - this->location.z) * 0.5;
}
void Point::draw() {
	ofSetColor(0,0,0,127);
	ofDrawSphere(this->location, 2);
}
void Point::setTarget() {
	if (ofRandom(100) < 80) {
		this->myr = ofGetWidth() / 2 * 0.8;
	}
	else {
		this->myr = ofGetWidth() / 4 * 0.8;
	}
	float phi = ofRandom(ofDegToRad(360));
	float unitZ = ofRandom(-1, 1);
	this->target.x = this->myr * sqrt(1 - unitZ * unitZ) * cos(phi);
	this->target.y = this->myr * sqrt(1 - unitZ * unitZ) * sin(phi);
	this->target.z = this->myr * unitZ;
}
//ofVec3f Point::getLocation() {
	//return this->location;
//}