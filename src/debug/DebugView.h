#pragma once
#include <iostream>
using namespace std;

#include "ofEvent.h"
#include "ofMain.h"
#include "..\text\StringUtils.h"


class DebugView
{
public:
	DebugView();
	~DebugView();

	void DebugView::setValue(string key, string val);
	void DebugView::appDraw(ofEventArgs &e);
	void DebugView::keyReleased(ofKeyEventArgs &e);
};

