#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	y_position = 0.0f;
	velocity = 0.0f;
	acceleration = 0.0f;
	gravity = .03f;
	flap_thrust = -gravity * 100;
	flapped = false;

	background.load("../../Debug/data/flappy_background.png");

	wings_up.load("../../Debug/data/wings_up.png");
	wings_down.load("../../Debug/data/wings_down.png");
	flap_sound.load("../../Debug/data/sfx_wing.wav");
	flap_sound.setMultiPlay(true);

	pipe1_position = 1500;
	pipe2_position = 1900;
	pipe3_position = 2300;
	pipe1_height = ofRandom(200, 800);
	pipe2_height = ofRandom(200, 800);
	pipe3_height = ofRandom(200, 800);
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
	
	pipe1_position -= 1.5f;
	pipe2_position -= 1.5f;
	pipe3_position -= 1.5f;
	if (pipe1_position < 0) {
		pipe1_height = ofRandom(200, 800);
		pipe1_position = 1210;
	} else if (pipe2_position < 0) {
		pipe2_height = ofRandom(200, 800);
		pipe2_position = 1210;
	} else if (pipe3_position < 0) {
		pipe3_height = ofRandom(200, 800);
		pipe3_position = 1210;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);
	background.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
	if (velocity > 0) {
		wings_up.draw(x_position - 170, y_position, 365.6f, 205.6f);
	}
	else {
		wings_down.draw(x_position - 100, y_position, 200.0f, 205.6f);
	}

	ofFill();
	ofSetColor(50, 150, 50, 0);
	ofDrawRectangle(0, 1315, 1000, 0);

	ofFill();
	ofSetColor(50, 150, 50);
	//draws bottom rectangle of first pipe
	ofDrawRectangle(pipe1_position, ground_height, -pipe_width, -pipe1_height);
	//draws top rectangle of first pipe
	ofDrawRectangle(pipe1_position, ground_height - pipe1_height - vert_pipe_space,
		-pipe_width, -top_pipe_height);

	//draws bottom rectangle of second pipe
	ofDrawRectangle(pipe2_position, ground_height, -pipe_width, -pipe2_height);
	//draws top rectangle of second pipe
	ofDrawRectangle(pipe2_position, ground_height - pipe2_height - vert_pipe_space,
		-pipe_width, -top_pipe_height);

	//draws bottom rectangle of third pipe
	ofDrawRectangle(pipe3_position, ground_height, -pipe_width, -pipe3_height);
	//draws top rectangle of third pipe
	ofDrawRectangle(pipe3_position, ground_height - pipe3_height - vert_pipe_space,
		-pipe_width, -top_pipe_height);
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
