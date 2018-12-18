#include "Webcambuffer.h"

ofFbo bufferr;
ofVideoGrabber webcam;
bool mirror = true;

WebcamBuffer::WebcamBuffer(int width, int height) {
	init(width, height, "");
}

WebcamBuffer::WebcamBuffer(int width, int height, string deviceName) {
	init(width, height, deviceName);
}

void WebcamBuffer::init(int width, int height, string deviceName) {
	// init FBO
	bufferr.allocate(width, height, GL_RGBA);

	// add listener to draw before main draw thread
	ofAddListener(ofEvents().update, this, &WebcamBuffer::appUpdate);

	// list devices
	vector<ofVideoDevice> devices = webcam.listDevices();
	for (vector<ofVideoDevice>::iterator it = devices.begin(); it != devices.end(); ++it) {
		cout << "id: " << it->id << endl;
		cout << "deviceName: " << it->deviceName << endl;
		cout << "hardwareName: " << it->hardwareName << endl;
		if (it->bAvailable == false) cout << "unavailable!" << endl;
		cout << "-------" << endl;

		// grab specific device if defined
		if (deviceName != "") {
			if (it->deviceName == deviceName) {
				webcam.setDeviceID(it->id);
				break;
			}
		}
	}

	// init with specific size
	webcam.setVerbose(true);
	webcam.setDesiredFrameRate(60);
	webcam.setup(width, height);
	ofSetVerticalSync(true);
}

WebcamBuffer::~WebcamBuffer() {
}

void WebcamBuffer::setMirror(bool isMirror) {
	mirror = isMirror;
}

ofFbo WebcamBuffer::getBuffer() {
	return bufferr;
}

ofVideoGrabber WebcamBuffer::getVideoGrabber() {
	return webcam;
}

void WebcamBuffer::appUpdate(ofEventArgs &e)
{
	// update camera
	webcam.update();

	// draw new frame to buffer
	if (webcam.isFrameNew()) {
		// init context
		bufferr.begin();
		ofBackground(0);
		if (mirror == true) {
			webcam.draw(webcam.getWidth(), 0, -webcam.getWidth(), webcam.getHeight());	// mirrored
		} else {
			webcam.draw(0, 0);
		}
		bufferr.end();
	}
}

