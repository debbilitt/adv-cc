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
    
    speedX 	= ofRandom(-1,1);
    speedY 	= ofRandom(-1,1);

    
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
    
    ofLoadImage(mTexture, "owen.jpg");
    
    ofDisableArbTex();

        mSphere.setRadius(70);
    
        mTexture.setTextureWrap(GL_NEAREST,GL_NEAREST);
        mTexture.setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    
        mSphere.mapTexCoordsFromTexture(mTexture);
    
    ofEnableDepthTest();
    
    
    
}

void Owen::update(){
    

    // increase x and y by adding speedX and speedY
    pointX += speedX;
    pointY += speedY;
//    
//    speedX = ofRandom(-1,1);
//    speedY = ofRandom(-1,2);
    
    //  check for collision, and trigger sounds:
    // horizontal collisions:
    if (pointX < 0){
        pointX = 0;
        speedX *= -1;
       wow1.play();
    } else if (pointX > ofGetWidth()){
        pointX = ofGetWidth();
        speedX *= -1;
        wow2.play();
    }
    // vertical collisions:
    if (pointY < 0 ){
        pointY = 0;
        speedY *= -1;
        wow3.play();
    } else if (pointY > ofGetHeight()){
        pointY = ofGetHeight();
        speedY *= -1;
        wow4.play();
    }
//    //  speed it up:
//    speedX 	+= 1.0f;
//    speedY 	+= 1.0f;
    

}

void Owen::draw(){
    

   owenTest.draw(pointX,pointY);

    
    /*non shader texture binding*/
    
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

    
}
