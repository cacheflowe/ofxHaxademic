#include "AnimationLoop.h"
#include "..\text\StringUtils.h"

int numFrames = 0;
double curFrame = 0;
double curProgress = 0;
double curProgressRads = 0;

bool rendering = false;
bool willRender = false;

ofImage img;

AnimationLoop::AnimationLoop(int frames)
{
	numFrames = frames;
	curFrame = 0;
	curProgress = 0;
	curProgressRads = 0;

	rendering = false;
	willRender = false;

	ofAddListener(ofEvents().keyReleased, this, &AnimationLoop::keyReleased);
	ofAddListener(ofEvents().draw, this, &AnimationLoop::appDraw);
}

AnimationLoop::~AnimationLoop()
{
}

int AnimationLoop::frames()
{
	return numFrames;
}

int AnimationLoop::loopCurFrame()
{
	return int(curFrame);
}

double AnimationLoop::progress()
{
	return curProgress;
}

double AnimationLoop::progressRads()
{
	return curProgressRads;
}

void AnimationLoop::startRender()
{
	willRender = true;
}

void AnimationLoop::appDraw(ofEventArgs &e)
{
	// animation loop progress calculation
	curFrame = ofGetFrameNum() % numFrames;
	curProgress = curFrame / double(numFrames);
	curProgressRads = curProgress * TWO_PI;
	// cout << "curProgress: " << curFrame << ", " << curProgressRads << endl;
	// if (P.p.debugView != null) P.p.debugView.setValue("AnimationLoop.progress()", progress);

	// check for willRender flag and kick off render
	if (curFrame == 0 && rendering) {
		rendering = false;
	}
	
	if (curFrame == 0 && willRender) {
		willRender = false;
		rendering = true;
	}

	// run render routines to save images
	if (rendering) {
		// SAVE IMAGES HERE
		img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		img.save("render-" + StringUtils::paddedNumber(curFrame, 8) + ".png");
	}
}

void AnimationLoop::keyReleased(ofKeyEventArgs &e) {
	// cout << "AnimationLoop::keyReleased! " << e.key << endl;
	if (e.key == 82) {	// Shift + R
		startRender();
	}
}
