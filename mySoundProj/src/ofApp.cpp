#include "ofApp.h"
#include "owen.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    
//    myVideoGrabber.setup(320,240);
//    myColorImage.allocate(myVideoGrabber.getWidth(),myVideoGrabber.getHeight());
//    myGrayscaleImage.allocate(myVideoGrabber.getWidth(),myVideoGrabber.getHeight());
//    myBackground.allocate(myVideoGrabber.getWidth(),myVideoGrabber.getHeight());
//    grayDifference.allocate(myVideoGrabber.getWidth(),myVideoGrabber.getHeight());
//
//
//    bLearnBackground = true;
//    threshold = 80;
//    ofSetBackgroundAuto(false);
 
    
   /*owen object*/
    
    for(int i=0; i<multiOwens.size(); i++){
        
        int randomX = ofRandom(0, ofGetWidth() );
        int randomY = ofRandom(0, ofGetHeight() );
        
        
        multiOwens[i].setup(randomX, randomY);
    }
    

}

//--------------------------------------------------------------
void ofApp::update(){

    
    /*webcam updating*/
//   
//    myVideoGrabber.update();
//
//    if(myVideoGrabber.isFrameNew()){
//        
//        myColorImage.setFromPixels(myVideoGrabber.getPixels());
//        
//        myGrayscaleImage = myColorImage; //operator overloading
//        
//        if (bLearnBackground == true) {
//            myBackground = myGrayscaleImage;
//            bLearnBackground == false;
//            
//        }
//        
//        grayDifference.absDiff(myGrayscaleImage, myBackground); //mom and dad, two parties, takes the difference
//        grayDifference.threshold(20); // determines the threshold of the gray difference lower is closer to white, higher is closer to black, 255 is the highest
//        
//    }
//    
//    
//    myContourFinder.findContours(grayDifference, 10, 100, 10, false);

   /*end webcam*/
    
   /*update object*/
       for(int i=0; i<multiOwens.size(); i++){
            multiOwens[i].update();
       }
}

//--------------------------------------------------------------
void ofApp::draw(){

    

//
//    myColorImage.draw(0,0);
//    grayDifference.draw(myColorImage.getWidth()+100,0);
    
    //if we want to draw an outline around our blob path
//    
//    ofPushMatrix();
//    ofNoFill();
//    
//    ofSetColor(ofColor::orange);
//    
//    
//    ofBeginShape();
//    //we loop through each of the detected blobs
//    //contourFinder.nBlobs gives us the number of detected blobs
//    for (int i = 0; i < myContourFinder.nBlobs; i++){
//        //each of our blobs contains a vector<ofPoints> pts
//        for(int j=0; j < myContourFinder.blobs[i].pts.size(); j++){
//            ofVertex(myContourFinder.blobs[i].pts[j].x, myContourFinder.blobs[i].pts[j].y);
//        }
//    }
    
    /*
     * Here is another way of looping through our contour blobs
     * Comment out the first nested for loop and uncomment this for an alternative method
     */
    //  //range-based for loop
    //	for(auto &blob : contourFinder.blobs){
    //		vector<ofPoint> pts = blob.pts;
    //		for(auto pt : pts){
    //			ofVertex(pt.x, pt.y);
    //		}
    //	}
    
    

//    ofEndShape();
//    
//    ofPopMatrix();
    
    /* draw owen's head: */
    
    for(int i=0; i<multiOwens.size(); i++){
        multiOwens[i].draw();
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
    multiOwens.push_back(tempOwen);

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
