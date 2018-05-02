#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	y_position = 0.0f;
	velocity = 0.0f;
	acceleration = 0.0f;
	gravity = .03f;
	flap_thrust = -gravity * 100;
	flapped = false;

	background.load("flappy_background.png");

	wings_up.load("wings_up.png");
	wings_down.load("wings_down.png");
	flap_sound.load("sfx_wing.wav");
	flap_sound.setMultiPlay(true);

	pipe1_position = ofGetWindowWidth();
	pipe2_position = ofGetWindowWidth();
	pipe3_position = ofGetWindowWidth();
	pipe1_height = ofRandom(500, 1000);
	pipe2_height = ofRandom(500, 1000);
	pipe3_height = ofRandom(500, 1000);
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
		pipe1_height = ofRandom(500, 1000);
		pipe1_position = ofGetScreenWidth();
	} else if (pipe2_position < 0) {
		pipe2_height = ofRandom(500, 1000);
		pipe2_position = ofGetScreenWidth();
	} else if (pipe3_position < 0) {
		pipe3_height = ofRandom(500, 1000);
		pipe3_position = ofGetScreenWidth();
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
	ofDrawRectangle(pipe1_position + 10, ground_height, -pipe_width, -pipe1_height);
	ofDrawRectangle(pipe1_position + 10, ground_height - pipe1_height - vert_pipe_space,
		-pipe_width, -vert_pipe_space);
	/*for (auto p : pipes) {
		if (p != 0) {
			ofFill();
			ofSetColor(50, 150, 50, 0);
			ofDrawRectangle(current_section * section_width + 10 - level_position, ofGetWindowHeight() - p,
				current_section * section_width + 15 - level_position, ofGetWindowHeight());
			ofFill();
			ofSetColor(50, 150, 50, 0);
			ofDrawRectangle(current_section * section_width + 10 - level_position, 0,
				current_section * section_width + 15 - level_position, ofGetWindowHeight() - 15);
		}
		current_section++;
	}*/
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
