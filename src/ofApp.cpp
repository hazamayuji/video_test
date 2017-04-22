#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofToggleFullscreen();
    ofSetBackgroundColor(0,0,0);
    ofEnableSmoothing();//画面の混色の設定を加算合成にする
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    
    camWidth = 480;
    camHeight = 320;
    
    vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(camWidth,camHeight);
    
    /*
    myPlayer.loadMovie("a.MOV");
    myPlayer.play();
    */
}

//--------------------------------------------------------------
void ofApp::update(){
    //myPlayer.update();
    vidGrabber.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //myPlayer.draw(0,0,ofGetWidth(),ofGetHeight());
    
    ofSetColor(0xffffff);
    vidGrabber.draw(10,20,ofGetWidth()/5,ofGetHeight()/5);
    
    unsigned char *pixels = vidGrabber.getPixels().getData();
    
    for(int i = 0; i < camWidth; i += 3){
        for(int j = 0; j < camHeight; j += 3){
            unsigned char r = pixels[(j * camWidth + i) * 3];
            unsigned char g = pixels[(j * camWidth + i) * 3 + 1];
            unsigned char b = pixels[(j * camWidth + i) * 3 + 2];
        
            ofSetColor(255, 0, 0, 100);
            ofDrawCircle(ofGetWidth()/5+20+i*2, 20+j*2, 4.0*(float)r/255.0);
            ofSetColor(0, 255, 0, 100);
            ofDrawCircle(ofGetWidth()/5+20+i*2, 20+j*2, 4.0*(float)r/255.0);
            ofSetColor(0, 0, 255, 100);
            ofDrawCircle(ofGetWidth()/5+20+i*2, 20+j*2, 4.0*(float)r/255.0);
            
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
