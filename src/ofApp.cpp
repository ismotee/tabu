#include "ofApp.h"

//--------------------------------------------------------------

void ofApp::setup() {
    controller.setup(120);
}

//--------------------------------------------------------------

void ofApp::update() {
    controller.update();
 
}

//--------------------------------------------------------------

void ofApp::draw() {
    controller.draw();
}

//--------------------------------------------------------------

void ofApp::keyPressed(int key) {
    
}

//--------------------------------------------------------------

void ofApp::keyReleased(int key) {
}

//--------------------------------------------------------------

void ofApp::mouseMoved(int x, int y) {
    controller.hiiri.moved(x,y);
}

//--------------------------------------------------------------

void ofApp::mouseDragged(int x, int y, int button) {
    controller.hiiri.moved(x,y);
}

//--------------------------------------------------------------

void ofApp::mousePressed(int x, int y, int button) {
    controller.hiiri.pressed(x,y);

}

//--------------------------------------------------------------

void ofApp::mouseReleased(int x, int y, int button) {
    controller.hiiri.released(x,y);
}

//--------------------------------------------------------------

void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------

void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------

void ofApp::windowResized(int w, int h) {
    controller.resize(w,h);
}

//--------------------------------------------------------------

void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------

void ofApp::dragEvent(ofDragInfo dragInfo) {

}