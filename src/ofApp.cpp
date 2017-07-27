#include "ofApp.h"

//--------------------------------------------------------------

void ofApp::setup() {
    controller.setup(120);
    oscGui.setup();
}

//--------------------------------------------------------------

void ofApp::update() {
    controller.update();
    GUI_info_T info = oscGui.getInfo();
    if(info.connecting) {
        oscGui.print("connecting to " + info.ip + " @ " + ofToString(info.senderPort) + "," + ofToString(info.receiverPort) + "...");
        controller.setAddress(info.ip, info.senderPort, info.receiverPort);
        if(!controller.connection) 
            controller.connect();
        if(controller.connection)
            oscGui.print("connected");
    }
    
    if(info.disconnecting ) {
        if(controller.connection) {
            oscGui.print("disconnecting");
            controller.disconnect();
        }
        else
            oscGui.print("not connected");
    }

 
}

//--------------------------------------------------------------

void ofApp::draw() {
    controller.draw();
    oscGui.draw();
}

//--------------------------------------------------------------

void ofApp::keyPressed(int key) {
    oscGui.handleKey(key);    
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

    if(oscGui.show)
        oscGui.handleClick(x,y);
    else
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
