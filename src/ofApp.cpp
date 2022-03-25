#include "ofApp.h"
#define LINE_NUM 1000

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofLogToConsole();
	ofSetFrameRate(60);
	ofSetBackgroundColor(255,255,200);

	gui.setup();
	general.add(fps.set("fps", "fps"));
	general.add(isDrawGui.set("isDrawGui", true));
	general.add(bgColor.set("bgColor", ofColor(0, 0, 0), ofColor(0, 0, 0), ofColor(255, 255, 255)));
	params.add(timeScalePos.set("time Scale Pos", 0.1, 0, 10));
	params.add(timeScaleColor.set("time Scale Color", 0.1, 0, 10));
	gui.add(general);
	gui.add(params);
	bgColor.addListener(this, &ofApp::updateBGColor);

	for (int i = 0; i < LINE_NUM; i++) {
		DrawLine line;
		lines.push_back(line);
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	fps = ofToString(ofGetFrameRate(), 2);
	for (int i = 0; i < LINE_NUM; i++) {
		// pos
		ofVec2f startPos, endPos;
		startPos.x = sin(i * 0.1 + ofGetElapsedTimef() * timeScalePos);
		startPos.x *= startPos.x * ofGetWidth();
		startPos.y = sin(i * 0.3 + ofGetElapsedTimef() * timeScalePos);
		startPos.y *= startPos.y * ofGetHeight();
		endPos.x = sin(i * 0.6 + ofGetElapsedTimef() * timeScalePos);
		endPos.y *= startPos.y * ofGetWidth();
		endPos.y = sin(i * 0.9 + ofGetElapsedTimef() * timeScalePos);
		endPos.y *= startPos.y * ofGetHeight();
		lines[i].setPos(startPos, endPos);
		//ofLogNotice() << startPos << ", " << endPos;
		
		// color
		float r = sin(i * 0.1 + ofGetElapsedTimef() * timeScaleColor) * 55.0 + 200;
		float g = sin(0 + ofGetElapsedTimef() * timeScaleColor) * 55.0 + 200;
		float b = sin(i * 0.1 + ofGetElapsedTimef() * timeScaleColor) * 55.0 + 200;
		lines[i].setColor(ofColor(r, g, b, 255));
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (auto &line : lines) {
		line.draw();
	}

	if(isDrawGui)
		gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key)
	{
	case 'g':
		isDrawGui = !isDrawGui;
		break;
	case 'c':
		capture();
		break;
	default:
		break;
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

//--------------------------------------------------------------
void ofApp::updateBGColor(ofColor &color) {
	ofSetBackgroundColor(color);
}

void ofApp::capture() {
	ofImage img;
	string name = "img/A01-" + ofGetTimestampString("%H-%M-%S") + ".png";
	img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
	img.save(name);
	ofLogNotice("capture") << name;
}

