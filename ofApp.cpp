#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofBackground(255);
	ofSetWindowTitle("day 5");
	ofEnableAlphaBlending();
	ofEnableDepthTest();
	for (int i = 0; i < 1500; i++) {
		this->points.push_back(shared_ptr<Point>(new Point()));
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < this->points.size(); i++) {
		this->points[i]->update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 0);
	ofRotateY(ofGetFrameNum() * 0.6);
	for (int i = 0; i < this->points.size(); i++) {
		this->points[i]->draw();
	}
	for (int j = 0; j < this->points.size(); j++) {
		for (int k = j + 1; k < this->points.size(); k++) {
			float d = this->points[j]->location.distance(this->points[k]->location);
			if (d < 100) {
				float mya = ofMap(d, 0, 199, 90, 5);
				ofSetColor(0, 0, 0, mya);
				ofDrawLine(this->points[j]->location, this->points[k]->location);
			}

		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'x') {
		string now = ofGetTimestampString("%Y%m%d%H%M%S");
		this->img.grabScreen(0, 0, 1000, 1000);
		this->img.saveImage("of" + now + ".jpg");
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
