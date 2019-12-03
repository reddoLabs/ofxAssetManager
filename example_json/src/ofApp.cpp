#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// setup assetManager
	assets.setup();

	// set a font style
	ofxFontStash2::Style style;
	style.fontID = "IndieFlower";
	style.fontSize = 100;
	assets.getFonts()->addStyle("catStyle", style);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	// set black background
	ofBackground(0);

	// draw texture and font
	assets.getTexture("cat").draw(0, 0);
	assets.getFonts()->draw("A fluffy cat", assets.getFonts()->getStyle("catStyle"), 50, 700);
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
