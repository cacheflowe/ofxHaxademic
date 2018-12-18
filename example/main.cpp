#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	// basic rendering
	// ofSetupOpenGL(1024,768,OF_WINDOW);

	// fancy rendering
	ofGLWindowSettings settings;
	settings.setGLVersion(3, 2);
	settings.setSize(1280, 720);
	settings.windowMode = OF_WINDOW; // OF_FULLSCREEN;
	ofCreateWindow(settings);

	// fire up the app
	ofRunApp(new ofApp());
}
