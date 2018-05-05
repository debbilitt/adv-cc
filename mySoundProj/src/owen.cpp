//
//  owen.cpp
//  mySoundProj
//
//  Created by Debbi Litt on 5/3/18.
//

#include "owen.h"

Owen::Owen(){

};


void Owen::setup(float x, float y){
 
    pointX = x;
    pointY = y;
    
    position = ofVec2f(pointX,pointY);
    
    speedX 	= ofRandom(-1,1);
    speedY 	= ofRandom(-1,1);

    speed = ofVec2f(speedX,speedY);
 
    
    owenTest.load("ow.png");
    
    
    //load sounds
    wow1.load("16.mp3");
    wow1.setMultiPlay(true);
    
    wow2.load("1.mp3");
    wow2.setMultiPlay(true);
    
    wow3.load("2.mp3");
    wow3.setMultiPlay(true);
    
    wow4.load("4.mp3");
    wow4.setMultiPlay(true);

    
    /*sphere owen*/
    
//    ofLoadImage(mTexture, "owen.jpg");
//
//        mSphere.setRadius(70);
//    
//        mTexture.setTextureWrap(GL_NEAREST,GL_NEAREST);
//        mTexture.setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
//    
//        mSphere.mapTexCoordsFromTexture(mTexture);
//    
//    ofEnableDepthTest();
//    
//    
    
}

void Owen::update(){
    

    // increase x and y by adding speedX and speedY
    pointX += speedX;
    pointY += speedY;

    
    //  check for collision, and trigger sounds:
    // horizontal collisions:
    if (pointX <= 0){
        speedX *= -1;
        wow1.play();
            ofLog() << pointX << endl;
    } else if (pointX >= ofGetWidth()){
        speedX *= -1;
        wow2.play();
            ofLog() << pointX << endl;
    }
    // vertical collisions:
    if (pointY <= 0 ){
        speedY *= -1;
        wow3.play();
            ofLog() << pointY << endl;
    } else if (pointY >= ofGetHeight()){
        speedY *= -1;
        wow4.play();
        ofLog() << pointY << endl;
    }
//    //  speed it up:
//    speedX 	+= 1.0f;
//    speedY 	+= 1.0f;
    

}

void Owen::draw(){
    
    /*draw owen img only*/
   owenTest.draw(pointX,pointY);

    
    /*texture binding on sphere*/
    
//    ofPushMatrix();
//            float spinX = sin(ofGetElapsedTimef()*.35f);
//            float spinY = cos(ofGetElapsedTimef()*.075f);
//    
//    
//            ofTranslate(pointX, pointY);
//    
//            mTexture.bind();
//    
//    
//            mSphere.draw(ofPolyRenderMode::OF_MESH_FILL);
//    
//            mSphere.rotate(spinX,1.0,0.0,0.0);
//            mSphere.rotate(spinY,0,1.0,0.0);
//        
//            mTexture.unbind();
//
//    ofPopMatrix();
}


void Owen::checkDistance(ofVec2f _contour){
    
    ofVec2f contour;
    contour = _contour;
    
    float distance = position.distance(contour);
    
    if(distance < 50){
        ofLog() << "wow" << endl;
//        speed *= +1;
    
    }
    
    
    
}

