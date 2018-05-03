#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
 
    //load sounds
    wow1.load("16.mp3");
    wow1.setMultiPlay(true);
    
    wow2.load("1.mp3");
    wow2.setMultiPlay(true);

    wow3.load("2.mp3");
    wow3.setMultiPlay(true);
  
    wow4.load("4.mp3");
    wow4.setMultiPlay(true);
    
    //load images
    owen.load("ow.png");
    wowtron.load("wowtron.png");
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofBackground(ofColor::darkBlue);
    
    // update the sound playing system:
    ofSoundUpdate();
    
    wowtron.update();
    
    
    // (1) we increase px and py by adding vx and vy
    px += vx;
    py += vy;
    
    // (2) check for collision, and trigger sounds:
    // horizontal collisions:
    if (px < 0){
        px = 0;
        vx *= -1;
        wow1.play();
    } else if (px > ofGetWidth()){
        px = ofGetWidth();
        vx *= -1;
        wow2.play();
    }
    // vertical collisions:
    if (py < 0 ){
        py = 0;
        vy *= -1;
        wow3.play();
    } else if (py > ofGetHeight()){
        py = ofGetHeight();
        vy *= -1;
        wow4.play();
    }
    // (3) slow down velocity:
    vx 	*= 0.996f;
    vy 	*= 0.996f;

   

}

//--------------------------------------------------------------
void ofApp::draw(){

    
    
//    wowtron.draw(0,ofGetHeight()/4);
    
// draw owen's head:


    owen.draw(px, py);
    
    
    
//        owen.draw(ofRandom(ofGetWidth()),200);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

//    wow1.setSpeed(ofRandom(0.8, 1.2));
//    wow2.setSpeed(ofRandom(0.8, 1.2));
//    wow3.setSpeed(ofRandom(0.8, 1.2));
//    wow4.setSpeed(ofRandom(0.8, 1.2));
//    
//    switch (key) {
//        case 'a':
//             wow1.play();
//            break;
//        case 's':
//             wow2.play();
//            break;
//        case 'd':
//             wow3.play();
//            break;
//        case 'f':
//             wow4.play();
//        case 'g':
//            wow1.play();
//            break;
//        case 'h':
//            wow2.play();
//            break;
//        case'j':
//            wow3.play();
//            break;
//        case'k':
//            wow4.play();
//            break;
//
//        default:
//            break;
//    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    // add into vx and vy a small amount of the change in mouse:
    vx += (x - prevx) / 20.0f;
    vy += (y - prevy) / 20.0f;
    // store the previous mouse position:
    prevx = x;
    prevy = y;

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
//    mySound.setSpeed(ofRandom(0.8, 1.2));
//    mySound.play();

    prevx = x;
    prevy = y;


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
