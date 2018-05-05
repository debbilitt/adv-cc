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
    threshold = 20;
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
    
//   /*update owen object*/
       for(int i=0; i<multiOwens.size(); i++){
            multiOwens[i].update();
       }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(ofColor::white);
    
    //if we want to draw an outline around our blob path
    ofSetColor(ofColor::white);
    ofPushMatrix();
    
    if (bShowVideo) {
        
        myColorImage.draw(0,0);
        grayDifference.draw(myColorImage.getWidth()+100,0);
        //        myGrayscaleImage.draw(0,myColorImage.getHeight()+100);
        //        myBackground.draw(myGrayscaleImage.getWidth()+100,myColorImage.getHeight()+100);
        
    }

    ofNoFill();
    ofSetColor(ofColor::orange);
    
//    ofBeginShape();
//    //we loop through each of the detected blobs
//    //contourFinder.nBlobs gives us the number of detected blobs
//    for (int i = 0; i < myContourFinder.nBlobs; i++){
//       
//      //range-based for loop
//    	for(auto &blob : myContourFinder.blobs){
//    		vector<ofPoint> pts = blob.pts;
//    		for(auto pt : pts){
//    			ofVertex(pt.x, pt.y);
//    
//                ofVec2f temp_contour;
//                temp_contour.set(pt.x,pt.y);
//    
//    /* check distance to owen's head: */
//                for(int i=0; i<multiOwens.size(); i++){
//                    multiOwens[i].checkDistance(temp_contour);
//                }
//    		}
//    	}
//
//    }
//
//    ofEndShape();
    
    /*centroid*/


//    ofBeginShape();
//    
//
for (int i = 0; i < myContourFinder.nBlobs; i++){
   
    for(auto &blob : myContourFinder.blobs){
        ofFill();
        ofSetColor(ofColor::orange);

        ofDrawCircle(blob.centroid.x, blob.centroid.y, 20);
        
        
        ofVec2f temp_contour;
        temp_contour.set(blob.centroid.x,blob.centroid.y);
        
        /* draw owen's head: */
        ofSetColor(ofColor::white);
        for(int i=0; i<multiOwens.size(); i++){
            multiOwens[i].checkDistance(temp_contour);
        }
        
    }
  
}
//    ofEndShape();

    
    
    ofPopMatrix();
    
    ofSetColor(ofColor::white);
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
