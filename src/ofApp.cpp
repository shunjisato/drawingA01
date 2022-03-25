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
	gui.add(general);

	bgColor.addListener(this, &ofApp::updateBGColor);

	for (int i = 0; i < LINE_NUM; i++) {
		DrawLine line;
		lines.push_back(line);
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	fps = ofToString(ofGetFrameRate(), 2);
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

