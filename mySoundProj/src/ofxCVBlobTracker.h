//
//  ofxCVBlobTracker.h
//  mySoundProj
//
//  Created by Debbi Lit on 5/7/18.
//
//

#ifndef oF_CV_BLOBTRACKER_H
#define oF_CV_BLOBTRACKER_H
#include <map>
#include <vector>
#include "ofMain.h"
#include "ofxCvTrackedBlob.h"
#include "ofxCvConstants_Track.h"
class ofxCvBlobTracker {
public:
    vector<ofxCvTrackedBlob> blobs;
    ofxCvBlobTracker();
    void trackBlobs( const vector<ofxCvBlob>& blobs );
