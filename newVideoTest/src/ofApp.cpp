#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
        myVideoGrabber.setup(320,240);
    
        myColorImage.allocate(myVideoGrabber.getWidth(),myVideoGrabber.getHeight());
        myGrayscaleImage.allocate(myVideoGrabber.getWidth(),myVideoGrabber.getHeight());
        myBackground.allocate(myVideoGrabber.getWidth(),myVideoGrabber.getHeight());
        grayDifference.allocate(myVideoGrabber.getWidth(),myVideoGrabber.getHeight());
    
    
        bLearnBackground = true;
        threshold = 80;
        ofSetBackgroundAuto(false);
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    /*webcam updating*/
    
        bool bNewFrame = false;
    
        myVideoGrabber.update();
    
        bNewFrame = myVideoGrabber.isFrameNew();

    
        if(bNewFrame){
    
            myColorImage.setFromPixels(myVideoGrabber.getPixels());
    
            myGrayscaleImage = myColorImage; //operator overloading
    
            if (bLearnBackground == true) {
                myBackground = myGrayscaleImage;
                bLearnBackground = false;
    
            }
    
            grayDifference.absDiff(myBackground, myGrayscaleImage); //mom and dad, two parties, takes the difference
            grayDifference.threshold(threshold); // determines the threshold of the gray difference lower is closer to white, higher is closer to black, 255 is the highest
    
        }
    
    
        myContourFinder.findContours(grayDifference, 10, (340*240)/3, 10, false);


}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if (bShowVideo) {
    
        myColorImage.draw(0,0);
        grayDifference.draw(myColorImage.getWidth()+100,0);
        myGrayscaleImage.draw(0,myColorImage.getHeight()+100);
        myBackground.draw(myGrayscaleImage.getWidth()+100,myColorImage.getHeight()+100);
        
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    
    switch (key){
        case 'w':
            ofBackground(ofColor::white);
            bShowVideo = !bShowVideo;
            break;
        case 'r':
            //something to reset background
            break;
        case '+':
            threshold ++;
            if (threshold > 255) threshold = 255;
            break;
        case '-':
            threshold --;
            if (threshold < 0) threshold = 0;
            break;
    }

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
