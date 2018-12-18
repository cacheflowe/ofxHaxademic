#include "TextureConcentricCircleWave.h"

ofFbo buffer;

TextureConcentricCircleWave::TextureConcentricCircleWave(int width, int height)
{
	// buffer.allocate(800, 600, GL_RGBA); // GL_RGBA32F
	// init FBO
	ofFbo::Settings settings;
	settings.numSamples = 4;
	settings.useDepth = true;
	settings.width = width;
	settings.height = height;
	buffer.allocate(settings);

	// add listener to draw before main draw thread
	ofAddListener(ofEvents().update, this, &TextureConcentricCircleWave::appUpdate);
}

TextureConcentricCircleWave::~TextureConcentricCircleWave()
{
}

ofFbo TextureConcentricCircleWave::getBuffer() {
	return buffer;
}

void TextureConcentricCircleWave::appUpdate(ofEventArgs &e)
{
	// init context
	buffer.begin();
	ofBackground(0, 0);
	DrawUtil::setDrawCenter();

	// set background
	ofNoFill();
	ofFill();
	ofSetCircleResolution(150);

	double curSize = buffer.getWidth() * 0.3; // 2.0;
	double spacing = 70;
	int i = 0;
	double progressRads = ofGetFrameNum() * 0.1;
	while (curSize > 0) {
		ofPushMatrix();
		ofSetColor(
			127 + 127 * sin(progressRads + 1 + i * 0.25),
			127 + 127 * sin(progressRads + 2 + i * 0.25),
			127 + 127 * sin(progressRads + 3 + i * 0.25)
		);
		ofSetColor(127 + 127 * sin(progressRads + i * 0.25));

		ofTranslate(buffer.getWidth() / 2, buffer.getHeight() / 2);
		// ofRotateYRad(0.1 * sin(progressRads + 3 + i * 0.25));
		// ofSetLineWidth(spacing * 0.2);	// doesn't work if using shaders :'(
		ofDrawCircle(0, 0, curSize);
		// ofDrawRectangle(0, 0, curSize, curSize);
		ofPopMatrix();
		curSize -= spacing;
		i++;
	}

	// end context
	buffer.end();
}
