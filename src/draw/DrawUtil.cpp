#include "DrawUtil.h"

DrawUtil::DrawUtil()
{
}

DrawUtil::~DrawUtil()
{
}

void DrawUtil::setDrawCenter() {
	ofSetRectMode(OF_RECTMODE_CENTER);
}

void DrawUtil::setDrawCorner() {
	ofSetRectMode(OF_RECTMODE_CORNER);
}

