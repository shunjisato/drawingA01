#pragma once
#include "ofMain.h"

class DrawLine
{
public:
	DrawLine();
	~DrawLine();
	void setPos(ofVec2f start, ofVec2f end);
	void setColor(ofColor color);
	void draw();

private:
	ofVec2f startPos;
	ofVec2f endPos;
	ofColor color;
};

