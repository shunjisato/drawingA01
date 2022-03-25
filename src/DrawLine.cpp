#include "DrawLine.h"
DrawLine::DrawLine() {
	startPos = ofVec2f(ofRandom(1000), ofRandom(1000));
	endPos = ofVec2f(ofRandom(1000), ofRandom(1000));
	color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
}

DrawLine::~DrawLine() {

}

void DrawLine::setup(ofVec2f start, ofVec2f end){

}

void DrawLine::setColor(ofColor color) {

}

void DrawLine::draw() {
	ofSetColor(color);
	ofDrawLine(startPos, endPos);
}
