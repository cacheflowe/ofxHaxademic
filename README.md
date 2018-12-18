# ofxHaxademic

A personal toolkit for openframeworks projects

## TO BUILD

- AppStore
	- AppStoreDistributed w/WebSockets
- General recent structure of Processing apps?
- How to make objects like DebugView globally-accessible?
	- Always use something like PAppletHax?
	- Or use singletons or static instances? In this case, is there an ofxHaxademic initializer that instantiate everything?
- DrawUtil / ImageUtil
- App properties like Processing?
- Renderer for video output
- Shader Filters & textures
- Robot-style screensaver killer
- Crash monitor / dashboard poster
- Easing/Linear Float objects & Penner equations
- Projection mapping tools & UI controls - https://github.com/julapy/ofxQuadWarp
- 1080p webcam - can it be threaded? currently drags down app framerate
- Video player @ 4k [NOT GOOD! Codecs?]

## TO FIGURE OUT

- Fastest method of copying pixels between FBOs?
- c++ overlap with fields between classes.. two objects with the same property/function name will cause an error?!
- Change code while running
	- > svgtiny.lib(svgtiny.obj) : MSIL .netmodule or module compiled with /GL found; restarting link with /LTCG; add /LTCG to the link command line to improve linker performance
	- > LINK : warning LNK4075 : ignoring '/INCREMENTAL' due to '/LTCG' specification
- Visual Studio Key commands
- How to run multiple apps within a project - HaxBaseApp?
- How to call out to shell scripts
- Precompiled headers?

## WHAT CAN OFX DO THAT JAVA CAN'T?

- Fancy face tracking
- YOLO object detection
- Openpose?
- Embed a modern browser?
- Float 32 texture out of the box
- Webcams with higher resolutions. 640x480 seems to be the max for Processing??

## WHAT STAYS IN JAVA FOR NOW

- WebSocket server
- Web Server & internet access stuff
- FileWatcher
- Email (sendgrid)
- Printing

## General notes:

* Shaders don't work without a fancier OpenGL setup:

```
ofGLWindowSettings settings;
settings.setGLVersion(3, 2);
settings.setSize(1024, 768);
ofCreateWindow(settings);
```

* Normalized shader coordinates are not default. To use them, your texture uniform must be `sampler2D` instead of `sampler2DRect`, which would be used if `ofDisableArbTex();` isn't called before textures are created.
