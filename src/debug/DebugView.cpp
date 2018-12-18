#include "DebugView.h"

#include <map>
#include <iostream>
#include <cassert>

bool active;
map<string, string> debugMap;
ofBitmapFont bitmapFont;


DebugView::DebugView()
{
	active = false;
	ofAddListener(ofEvents().keyReleased, this, &DebugView::keyReleased);
	ofAddListener(ofEvents().draw, this, &DebugView::appDraw);
}

DebugView::~DebugView()
{
}

void DebugView::setValue(string key, string value) {
	debugMap[key] = value;
	// check if key is present
	// if (debugMap.find("world") != debugMap.end())
	//	 std::cout << "map contains key world!\n";
}

void DebugView::appDraw(ofEventArgs &e)
{
	if(active == true) {
		// concat debug text
		string debugOut = "";
		debugOut += "RUNTIME \n";
		debugOut += "----------- \n";
		debugOut += "FrameRate: " + to_string(int(ofGetFrameRate())) + "\n";
		debugOut += "FrameNum: " + to_string(int(ofGetFrameNum())) + "\n";
		debugOut += "Time: " + StringUtils::secondsToFormattedTime(round(ofGetElapsedTimeMillis() / 1000)) + "\n";
		debugOut += "Time (seconds): " + to_string(int(round(ofGetElapsedTimeMillis() / 1000))) + "\n";

		// add custom values
		debugOut += "\nCUSTOM \n";
		debugOut += "----------- \n";
		map<string, string>::iterator it;
		for (it = debugMap.begin(); it != debugMap.end(); it++) {
			debugOut += it->first + ": " + it->second + "\n";	// first/second is key/value
		}

		// get text width
		ofRectangle textSizeRect = bitmapFont.getBoundingBox(debugOut, 0, 0, OF_BITMAPMODE_SIMPLE);

		// draw background
		ofFill();
		ofSetRectMode(OF_RECTMODE_CORNER);
		ofSetColor(0, 200);
		ofDrawRectangle(0, 0, textSizeRect.width + 20, ofGetHeight());

		// draw text to screen
		ofSetColor(255);
		ofDrawBitmapString(debugOut, 10, 20);
		
		// reset context
		// ofSetRectMode(OF_RECTMODE_CENTER);
	}
}

void DebugView::keyReleased(ofKeyEventArgs &e) {
	// cout << "keyReleased! active == " << active << endl;
	if (e.keycode == 47) {
		active = !active;
	}
}

