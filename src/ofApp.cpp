#include "ofApp.h"

//--------------------------------------------------------------

void ofApp::setup() {
    controller.setup(120); //set controller @ 120 fps
    oscGui.setup();
}

//--------------------------------------------------------------

void ofApp::update() {
    //päivitä kaikki jutut
    controller.update();
    oscGui.update();
    
    //hae tiedot GUI:sta
    GUI_info_T info = oscGui.getInfo();
    
    //jos on painettu connect-buttonia, käske controlleria vaihtamaan osoitetta
    if(info.connecting) {
        controller.setAddress(info.ip, info.senderPort, info.receiverPort);
        if(!controller.connection) 
            controller.connect();
    }
    
    //jos on painettu disconnect-buttonia, käske controlleria lopettamaan lähetys
    if(info.disconnecting ) {
        if(controller.connection)
            controller.disconnect();
    }
    
    //kerro GUIn päätteessä näppäinkomennot
    oscGui.print("Press + or - to cycle through input devices");
    oscGui.print(""); //rivinvaihto
    
    //kerro GUIn päätteessä yhteyden tiedot
    if(controller.connection) {
        oscGui.print("Sending"); //TODO: kerro mihin osoitteeseen ja mitä lähetetään!
        oscGui.print(""); //rivinvaihto
    }        

    //kerro GUIn päätteessä HID-laitteen tiedot
    if(hidpen::isOpen)
        oscGui.print("Device " + ofToString(hidpen::currentDevice_i) + " is open");
    else
        oscGui.print("No HID devices open");
    if(controller.penExists) {        
        oscGui.print("Device is pressure pen");
        oscGui.print("Pressure: " + ofToString(hidpen::pressure) );
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
    
    //hidpen: vaihdetaan laitetta
    if(key == '+') {
        hidpen::nextDevice();
        controller.penExists = false;
    }
    if(key == '-') {
        hidpen::prevDevice();
        controller.penExists = false;
    }
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
