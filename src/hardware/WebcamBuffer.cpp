#include "Webcambuffer.h"

ofFbo bufferr;
ofVideoGrabber cam;
bool mirror = true;

WebcamBuffer::WebcamBuffer(int width, int height) {
	init(width, height, "");
}

WebcamBuffer::WebcamBuffer(int width, int height, string deviceName) {
	init(width, height, deviceName);
}

void WebcamBuffer::init(int width, int height, string deviceName) {
	// init FBO
	bufferr.allocate(width, height, GL_RGBA); // GL_RGBA32F

	// add listener to draw before main draw thread
	ofAddListener(ofEvents().update, this, &WebcamBuffer::appUpdate);

	// init cam
	cam.setVerbose(true);
	
	// list devices
	vector<ofVideoDevice> devices = cam.listDevices();
	for (vector<ofVideoDevice>::iterator it = devices.begin(); it != devices.end(); ++it) {
		cout << "id: " << it->id << endl;
		cout << "deviceName: " << it->deviceName << endl;
		cout << "hardwareName: " << it->hardwareName << endl;
		cout << "-------" << endl;

		// grab specific device if defined
		if (deviceName != "") {
			if (it->deviceName == deviceName) {
				cam.setDeviceID(it->id);
				break;
			}
		}
	}

	// init with specific size
	cam.setup(width, height);
	// cam.setDeviceID(12);
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
	return cam;
}

void WebcamBuffer::appUpdate(ofEventArgs &e)
{
	// update camera
	cam.update();

	// init context
	bufferr.begin();
	ofBackground(0);
	if (mirror == true) {
		cam.draw(cam.getWidth(), 0, -cam.getWidth(), cam.getHeight());	// mirrored
	} else {
		cam.draw(0, 0);
	}
	bufferr.end();
}

