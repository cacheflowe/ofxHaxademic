#pragma once
#include <iostream>
using namespace std;

#include "ofEvent.h"
#include "ofMain.h"


class AnimationLoop
{
public:
	AnimationLoop(int frames);
	~AnimationLoop();

	int AnimationLoop::frames();
	int AnimationLoop::loopCurFrame();
	double AnimationLoop::progress();
	double AnimationLoop::progressRads();

	void AnimationLoop::appDraw(ofEventArgs &e);

	void AnimationLoop::startRender();
	void AnimationLoop::keyReleased(ofKeyEventArgs &e);
};

