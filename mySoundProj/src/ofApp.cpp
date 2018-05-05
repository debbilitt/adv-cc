#include "ofApp.h"
#include "owen.h"

//--------------------------------------------------------------
void ofApp::setup(){

    /*setup video*/
    myVideoGrabber.setup(320,240);
    
    myColorImage.allocate(myVideoGrabber.getWidth(),myVideoGrabber.getHeight());
    myGrayscaleImage.allocate(myVideoGrabber.getWidth(),myVideoGrabber.getHeight());
    myBackground.allocate(myVideoGrabber.getWidth(),myVideoGrabber.getHeight());
    grayDifference.allocate(myVideoGrabber.getWidth(),myVideoGrabber.getHeight());
    
    
    bLearnBackground = true;
    threshold = 80;
    ofSetBackgroundAuto(false);
 
    
   /*owen object setup*/
    
    for(int i=0; i<multiOwens.size(); i++){
        
        int randomX = ofRandom(0, ofGetWidth() );
        int randomY = ofRandom(0, ofGetHeight() );
        
        
        multiOwens[i].setup(randomX, randomY);
    }
    

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

    /*end webcam*/
    
   /*update owen object*/
       for(int i=0; i<multiOwens.size(); i++){
            multiOwens[i].update();
       }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(ofColor::white);

    ofPushMatrix();
    
    if (bShowVideo) {
        
        myColorImage.draw(0,0);
        grayDifference.draw(myColorImage.getWidth()+100,0);
        myGrayscaleImage.draw(0,myColorImage.getHeight()+100);
        myBackground.draw(myGrayscaleImage.getWidth()+100,myColorImage.getHeight()+100);
        
    }
    
    
    ofPopMatrix();
    
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


    /*toggle background, adjust threshold*/
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
    
  
    
    Owen tempOwen;
    tempOwen.setup(x,y);	// setup its initial state
    multiOwens.push_back(tempOwen);



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
