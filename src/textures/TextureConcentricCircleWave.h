#pragma once
#include <iostream>
using namespace std;

#include "ofEvent.h"
#include "ofMain.h"
#include "DrawUtil.h"

class TextureConcentricCircleWave
{
public:
	TextureConcentricCircleWave(int width, int height);
	~TextureConcentricCircleWave();

	ofFbo TextureConcentricCircleWave::getBuffer();
	void TextureConcentricCircleWave::appUpdate(ofEventArgs &e);
};

