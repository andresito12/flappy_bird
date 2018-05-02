#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//load png images for background and both bird states
	background.load("../../Debug/data/flappy_background.png");

	wings_up.load("../../Debug/data/wings_up.png");
	wings_down.load("../../Debug/data/wings_down.png");
	
	//load wav files for sound effects
	flap_sound.load("../../Debug/data/sfx_wing.wav");
	flap_sound.setMultiPlay(true);
	pipe_pass.load("../../Debug/data/sfx_point.wav");
	pipe_pass.setMultiPlay(true);
	die.load("../../Debug/data/sfx_hit.wav");
	fall.load("../../Debug/data/sfx_die.wav");

	//bird variables
	bird_y_position = 0.0f;
	bird_velocity = 0.0f;
	bird_acceleration = 0.0f;
	bird_flapped = false;

	//pipe variables
	pipe1_position = 1500;
	pipe2_position = 1900;
	pipe3_position = 2300;
	pipe1_height = ofRandom(200, 800);
	pipe2_height = ofRandom(200, 800);
	pipe3_height = ofRandom(200, 800);
}

//--------------------------------------------------------------
void ofApp::update(){
	//bird physics
	if (bird_flapped) {
		bird_acceleration = 0.0f;
		bird_velocity = bird_flap_thrust;
		bird_flapped = false;
	} else {
		bird_acceleration += bird_gravity;
	}
	if (bird_acceleration >= bird_gravity) {
		bird_acceleration = bird_gravity;
	}
	bird_velocity += bird_acceleration;
	bird_y_position += bird_velocity;
	
	//level scrolling for pipes
	pipe1_position -= 1.0f;
	pipe2_position -= 1.0f;
	pipe3_position -= 1.0f;
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

	//check for successful pass thorugh pipe
	if (bird_x_position == pipe1_position - 150
		|| bird_x_position == pipe2_position - 150
		|| bird_x_position == pipe3_position - 150) {
		pipe_pass.play();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	//set and draw background
	ofSetColor(255);
	background.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());

	//draws wings up bird if falling
	//else draw wings down bird if flapping
	if (bird_velocity > 0) {
		wings_up.draw(wings_up_x_pos, bird_y_position, wings_up_width, wings_up_height);
	} else {
		wings_down.draw(wings_down_x_pos, bird_y_position, wings_down_width, wings_down_height);
	}

	//rectangle that fills ground
	ofFill();
	ofSetColor(50, 150, 50, 0);
	ofDrawRectangle(0, 1315, 1000, 0);

	//sets color and fill for all three pipes
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
			bird_flapped = true;
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
