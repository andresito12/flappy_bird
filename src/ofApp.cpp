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

	level_position = 0.0f;
	section_width = ofGetWindowWidth() / (pipes.size() - 1);
	current_section = 0;
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
	
	level_position += 14.0f;
	if (level_position > section_width) {
		level_position -= section_width;
		pipes.pop_front();
		int i = rand() % (ofGetWindowHeight() - 20);
		pipes.push_back(i);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	//ofDrawCircle(x_position, y_position, 50);
	background.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
	if (velocity > 0) {
		wings_up.draw(x_position - 170, y_position, 365.6f, 205.6f);
	}
	else {
		wings_down.draw(x_position - 100, y_position, 200.0f, 205.6f);
	}
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
