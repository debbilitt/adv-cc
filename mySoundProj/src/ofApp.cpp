#include "ofApp.h"
#include "owen.h"

//--------------------------------------------------------------
void ofApp::setup(){

    /*setup video*/
    myVideoGrabber.setup(ofGetWidth(),ofGetHeight());
    
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
        
        grayDifference.absDiff(myBackground, myGrayscaleImage);
        grayDifference.threshold(threshold);
        
    }
    
    
    myContourFinder.findContours(grayDifference, 10, (myVideoGrabber.getWidth()*myVideoGrabber.getHeight())/3, 2, true);

    /*end webcam*/
    
   /*update owen object*/
       for(int i=0; i<multiOwens.size(); i++){
            multiOwens[i].update();
       }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(ofColor::white);
    
    ofSetColor(ofColor::white);
    
    ofPushMatrix();
    
    if (bShowVideo) {
        
        myColorImage.draw(0,0);
//        grayDifference.draw(myColorImage.getWidth()+100,0);
        //   myGrayscaleImage.draw(0,myColorImage.getHeight()+100);
        //    myBackground.draw(myGrayscaleImage.getWidth()+100,myColorImage.getHeight()+100);
        
    }

    ofNoFill();
    ofSetColor(ofColor::orange);

    
    /*contour detection*/
    
  ofBeginShape();
    //we loop through each of the detected blobs
    //contourFinder.nBlobs gives us the number of detected blobs
    for (int i = 0; i < myContourFinder.nBlobs; i++){
       
      //range-based for loop
    	for(auto &blob : myContourFinder.blobs){
    		vector<ofPoint> pts = blob.pts;
    		for(auto pt : pts){
    			ofVertex(pt.x, pt.y);
    
                ofVec2f temp_contour;
                temp_contour.set(pt.x,pt.y);
    
    /* check distance to owen's head: */

                for (int i =0; i < multiOwens.size(); i++) {
                    
//                float distance = ofDist(pt.x,pt.y, multiOwens[i].pointX, multiOwens[i].pointY);
                    
                  ofVec2f owenPos;
                  owenPos.set(multiOwens[i].pointX, multiOwens[i].pointY);

                  float distance = owenPos.distance(temp_contour);

//                  ofVec2f speed;
//
//                  speed.set(multiOwens[i].speedX, multiOwens[i].speedY);

                    if (distance < 20) {
//                     speed *= -1;
//                        
//                    multiOwens[i].speedX *= -2;
//                    multiOwens[i].speedY *= -1;
//
                        
                        multiOwens[i].checkDistance();
                    ofLog() << "wow" << endl;
                    }
                }

                
    		}
    	}

    }

    ofEndShape();


/*draw bounding rectangle of blobs*/
//    myContourFinder.draw(0, 0, ofGetWidth(), ofGetHeight());
//    for(int i = 0; i < myContourFinder.nBlobs; i++) {
//        ofRectangle r = myContourFinder.blobs.at(i).boundingRect;
//        
//    }
//    
    
    
/*blob centroid detection*/

//    for (int i = 0; i < myContourFinder.nBlobs; i++){
//
//        for(auto &blob : myContourFinder.blobs){
//                ofFill();
//                ofSetColor(ofColor::orange);
//                ofDrawCircle(blob.centroid.x, blob.centroid.y, 20);
//
//                ofVec2f temp_contour;
//                temp_contour.set(blob.centroid.x,blob.centroid.y);
//
//                ofVec2f temp_contourNorm = temp_contour.getNormalized();
//            
//        
//        /* move owen's head: */
//        ofSetColor(ofColor::white);
//        for (int i =0; i < multiOwens.size(); i++) {
//
//            ofVec2f  owenPos;
//            owenPos.set(multiOwens[i].pointX, multiOwens[i].pointY);
//            
//           ofVec2f owenPosNorm = owenPos.getNormalized();
//            
//             float distance = owenPos.distance(temp_contour);
//
//      float distance = ofDist(blob.centroid.x,blob.centroid.y, multiOwens[i].pointX, multiOwens[i].pointY);
//          
//            if (distance < 50) {
//                multiOwens[i].speedX *= -1;
//               multiOwens[i].speedY *= -1;
//                multiOwens[i].speedX++;
//
//                ofLog() << "wow" << endl;
//            } else {
//            
//                ofLog() << "not close" << endl;
//            }
//        }
//    }
//  
//}

    ofPopMatrix();
 
    
    
    
    ofSetColor(ofColor::white);
    for(int i=0; i<multiOwens.size(); i++){
        multiOwens[i].draw();
    }
    
    ofSetColor(ofColor::blueSteel);
    ofDrawBitmapString("Press w to toggle video and s to reset video background", 0, 10);
    ofDrawBitmapString("Press d to remove an Owen or r to reset", 0, 30);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){


    /*toggle background, adjust threshold*/
    switch (key){
        case 'w':
            ofBackground(ofColor::white);
            bShowVideo = !bShowVideo;
            break;
        case 's':
            bLearnBackground = true;
        case 'd':
            for (int i =0; i < multiOwens.size(); i++) {
            multiOwens.erase(multiOwens.begin()+i);
            }
            break;
        case 'r':
            for (int i =0; i < multiOwens.size(); i++) {
                multiOwens.clear();
            }
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
