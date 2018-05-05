#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "owen.h"
#include "ofxOpenCv.h"
#define NOWENS 5

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
        void onButtonPress();
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

    
//    ofSpherePrimitive mSphere;
//    
//    ofTexture mTexture;

    
    ofImage owen;
    ofImage wowtron;
    
    // bounce around:
    //    float pointX = ofGetWidth()/2;
    //    float pointY = ofGetHeight()/2;
    //    float velocityX = 0;
    //    float velocityY = 0;
    //    float prevx, prevy;
    
    
    //webcam detection
    
    ofVideoGrabber myVideoGrabber;
    ofxCvColorImage myColorImage;
    ofxCvGrayscaleImage myGrayscaleImage;
    ofxCvGrayscaleImage myBackground;
    ofxCvGrayscaleImage grayDifference; //can use this in a Fbo mask
    
    ofxCvContourFinder myContourFinder;

    int 			threshold;
    bool			bLearnBackground;
    bool			bShowVideo = true;
    
    
    //owen object
    
    Owen mOwen;
    
//    Owen multiOwens[6];
    
    
    vector <Owen> multiOwens;
    
    
    
    
};
