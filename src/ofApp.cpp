#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	y_position = 0.0f;
	velocity = 0.0f;
	acceleration = 0.0f;
	gravity = .03f;
	flap_thrust = -gravity * 100;
	flapped = false;

	flappy_bird.load("flappy_bird_image.jpg");
	flap_sound.load("sfx_wing.wav");
	flap_sound.setMultiPlay(true);
}

//--------------------------------------------------------------
void ofApp::update(){
	if (flapped) {
		acceleration = 0.0f;
		velocity = flap_thrust;
		flapped = false;
	} else {
		acceleration += gravity;
	}
	if (acceleration >= gravity) {
		acceleration = gravity;
	}
	velocity += acceleration;
	y_position += velocity;
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofDrawCircle(x_position, y_position, 50);
	//flappy_bird.draw(x_position, y_position, 50, 50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
		case ' ':
			flapped = true;
			flap_sound.play();
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
