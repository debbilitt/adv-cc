#include "ofApp.h"
#include "owen.h"

//--------------------------------------------------------------
void ofApp::setup(){
 
    /*load sounds*/
//    wow1.load("16.mp3");
//    wow1.setMultiPlay(true);
   
//    wow2.load("1.mp3");
//    wow2.setMultiPlay(true);

//    wow3.load("2.mp3");
//    wow3.setMultiPlay(true);
  
//    wow4.load("4.mp3");
//    wow4.setMultiPlay(true);
   
    /*load images*/
//    owen.load("ow.png");
//    wowtron.load("wowtron.png");
//    
   
    
    /*grab texture for sphere*/
    
    
//    ofLoadImage(mTexture, "owen.jpg");
//    
//    ofDisableArbTex();
//    
//    mSphere.setRadius(70);
//
//    mTexture.setTextureWrap(GL_NEAREST,GL_NEAREST);
//    mTexture.setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
//    
//    mSphere.mapTexCoordsFromTexture(mTexture);
//    
//    ofEnableDepthTest();
    
   /*owen object*/
    
    for(int i=0; i<groupofOwens.size(); i++){
        
        int randomX = ofRandom( 0, ofGetWidth() );
        int randomY = ofRandom( 0, ofGetHeight() );
        
        groupofOwens[i].setup(randomX, randomY);
    }
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
//    ofBackground(ofColor::darkBlue);
    
    // update the sound playing system:
    ofSoundUpdate();
    
//    wowtron.update();
    
    
//    // (1) we increase x and y by adding velocityX and velocityY
//    pointX += velocityX;
//    pointY += velocityY;
//    
//    // (2) check for collision, and trigger sounds:
//    // horizontal collisions:
//    if (pointX < 0){
//        pointX = 0;
//        velocityX *= -1;
//        wow1.play();
//    } else if (pointX > ofGetWidth()){
//        pointX = ofGetWidth();
//        velocityX *= -1;
//        wow2.play();
//    }
//    // vertical collisions:
//    if (pointY < 0 ){
//        pointY = 0;
//        velocityY *= -1;
//        wow3.play();
//    } else if (pointY > ofGetHeight()){
//        pointY = ofGetHeight();
//        velocityY *= -1;
//        wow4.play();
//    }
//    // (3) slow down velocity:
//    velocityX 	*= 0.996f;
//    velocityY 	*= 0.996f;
//
//
    
   /*update object*/
       for(int i=0; i<groupofOwens.size(); i++){
            groupofOwens[i].update();
       }
}

//--------------------------------------------------------------
void ofApp::draw(){

    
//    wowtron.draw(0,ofGetHeight()/4);
    
    
    /*non shader texture binding*/
    
//        float spinX = sin(ofGetElapsedTimef()*.35f);
//        float spinY = cos(ofGetElapsedTimef()*.075f);
//    
//    
//        ofTranslate(pointX, pointY);
//    
//        mTexture.bind();
//    
//    
//        mSphere.draw(ofPolyRenderMode::OF_MESH_FILL);
//    
//        mSphere.rotate(spinX,1.0,0.0,0.0);
//        mSphere.rotate(spinY,0,1.0,0.0);
//    
//        mTexture.unbind();
    

    
    
    /* draw owen's head: */
    
    for(int i=0; i<groupofOwens.size(); i++){
        groupofOwens[i].draw();
    }

    
    
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
    
    
//    velocityX += (x - prevx) / 10.0f;
//    velocityY += (y - prevy) / 10.0f;
 
    // store the previous mouse position:
//    prevx = x;
//    prevy = y;

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
//    mySound.setSpeed(ofRandom(0.8, 1.2));
//    mySound.play();
    
    
    Owen tempOwen;
    tempOwen.setup(x,y);	// setup its initial state
    groupofOwens.push_back(tempOwen);

    //why does this only make two spheres - kevin

//    prevx = x;
//    prevy = y;


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
