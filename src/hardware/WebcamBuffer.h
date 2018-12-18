#pragma once
#include <iostream>
using namespace std;

#include "ofEvent.h"
#include "ofMain.h"


class WebcamBuffer
{
public:
	WebcamBuffer::WebcamBuffer(int width, int height);
	WebcamBuffer::WebcamBuffer(int width, int height, string deviceName);
	~WebcamBuffer();
	
	void WebcamBuffer::init(int width, int height, string deviceName);
	void WebcamBuffer::setMirror(bool isMirror);
	ofFbo WebcamBuffer::getBuffer();
	ofVideoGrabber WebcamBuffer::getVideoGrabber();
	void WebcamBuffer::appUpdate(ofEventArgs &e);
};

