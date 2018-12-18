#include "ofApp.h"

#include "DebugView.h"
#include "DrawUtil.h"
#include "AnimationLoop.h"
#include "TextureConcentricCircleWave.h"
#include "WebcamBuffer.h"

DebugView* debug;
AnimationLoop* loop;
TextureConcentricCircleWave* myTexture;
WebcamBuffer* webcam;

ofFbo transCam;
ofFbo feedbackBuffer;
ofShader chromaShader;
ofShader feedbackShader;

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofDisableArbTex();	

	debug = new DebugView();
	loop = new AnimationLoop(180);
	myTexture = new TextureConcentricCircleWave(1280, 720);
	webcam = new WebcamBuffer(1280, 720, "Logitech HD Pro Webcam C920");
	// webcam = new WebcamBuffer(1280, 720);

	// build buffers
	transCam.allocate(1280, 720, GL_RGBA);
	feedbackBuffer.allocate(1280, 720, GL_RGBA32F);

	// feedbackBuffer.begin();
	// ofBackground(0, 0);
	// feedbackBuffer.end();

	// load shaders
	chromaShader.load("haxademic/shaders/default.vert", "haxademic/shaders/leave-white.glsl");
	feedbackShader.load("haxademic/shaders/default.vert", "haxademic/shaders/feedback-radial.glsl");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	// add debug values
	debug->setValue("loop.frames()", to_string(loop->loopCurFrame()) + " / " + to_string(loop->frames()));
	debug->setValue("loop.progress()", to_string(loop->progress()));

	// draw texture
	DrawUtil::setDrawCorner();
	// myTexture->getBuffer().draw(0, 0);

	// draw webcam
	// webcam->getBuffer().draw(0, 0);

	// draw webcam with shader to transparent buffer
	double mousePercentX = (double)ofGetMouseX() / (double)ofGetWidth();
	double mousePercentY = (double)ofGetMouseY() / (double)ofGetHeight();
	debug->setValue("mousePercentX", to_string(mousePercentX));
	debug->setValue("mousePercentY", to_string(mousePercentY));

	// run webcam through chroma shader
	transCam.begin();
	ofBackground(0, 0);
	chromaShader.begin();
	chromaShader.setUniformTexture("tex0", transCam.getTexture(), 0);
	chromaShader.setUniform1f("crossfade", mousePercentY);
	webcam->getBuffer().draw(0, 0);
	// webcam->getVideoGrabber().draw(0, 0);
	chromaShader.end();
	transCam.end();

	// apply feedback and draw transparent pixels on top!!!
	feedbackBuffer.begin();
	feedbackShader.begin();
	// feedbackShader.setUniformTexture("tex0", transCam.getTexture(), 0);
	feedbackShader.setUniformTexture("tex0", feedbackBuffer, 0);
	feedbackShader.setUniform1f("amp", 0.01 * mousePercentX);
	feedbackShader.setUniform1f("sampleMult", 0.99);
	feedbackShader.setUniform1f("alphaMult", 0.99);
	feedbackBuffer.draw(0, 0);
	transCam.draw(0, 0);
	// myTexture->getBuffer().draw(0, 0);
	feedbackShader.end();
	feedbackBuffer.end();

	// test draw transparent webcam
	feedbackBuffer.draw(0, 0);

	// debug view textures
	// myTexture->getBuffer().draw(0, 0, 120, 72);
	// webcam->getBuffer().draw(0, 72, 120, 72);
	// transCam.draw(0, 144, 120, 72);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
