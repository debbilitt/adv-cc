#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofSoundPlayer wow1;
    ofSoundPlayer wow2;
    ofSoundPlayer wow3;
    ofSoundPlayer wow4;

   
    ofImage owen;
    ofImage wowtron;
    
    void onButtonPress();
    
    
    // we will bounce a circle using these variables:
    float px = ofGetWidth()/2;
    float py = ofGetHeight()/2;
    float vx = 0;
    float vy = 0;
    float prevx, prevy;
    
    static constexpr size_t nBandsToGet = 128;
    std::array<float, nBandsToGet> fftSmoothed{{0}};
		
};
