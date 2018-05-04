//
//  owen.h
//  mySoundProj
//
//  Created by Debbi Litt on 5/3/18.
//

#ifndef owen_hp
#define owen_hp
#include "ofMain.h"
#include <stdio.h>

class Owen {
    
public:
    
    // methods, equivalent to specific functions of your class objects
    void setup(float x, float y);
    void update();
    void draw();
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseMoved(int x, int y );


//    void checkDistance(); //check its distance to the other vector

    // variables
    float pointX;   // position
    float pointY;
    float speedY;   // speed and direction
    float speedX;
    float prevx;   // previous location
    float prevy;
    
    /*sound files*/
    ofSoundPlayer wow1;
    ofSoundPlayer wow2;
    ofSoundPlayer wow3;
    ofSoundPlayer wow4;
    
    /*load an owen*/
    ofImage owenTest;
    
    
    /*texture wrapping*/
    
    ofSpherePrimitive mSphere;
    ofTexture mTexture;

    
    Owen();  // constructor - used to initialize an object, if no properties are passed the program sets them to the default value
    
    
    
    
private:
};

#endif /* owen_h */
