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

	//load flappy font for score
	flappy_font.load("../../Debug/data/04B_19__.TTF", 100);

	//bird variables
	bird_y_position = 0.0f;
	bird_velocity = 0.0f;
	bird_acceleration = 0.0f;
	bird_flapped = false;
	bird_is_dead = false;

	//pipe variables
	pipe1_position = 1500;
	pipe2_position = 1900;
	pipe3_position = 2300;
	pipe1_height = ofRandom(200, 800);
	pipe2_height = ofRandom(200, 800);
	pipe3_height = ofRandom(200, 800);

	//miscellaneous variables
	score = 0;
	sound_played = false;
	hitbox_x = wings_down_x_pos + 50;
	hitbox_y = bird_y_position + 50;
}

//--------------------------------------------------------------
void ofApp::update(){	
	flapAndFall();
	capAcceleration();
	updateBirdAndHitbox();
	scrollPipes();
	hitDetectionPipe1();
	hitDetectionPipe2();
	hitDetectionPipe3();
	passPipe();
}

//--------------------------------------------------------------
void ofApp::draw(){
	//set and draw background
	ofSetColor(255);
	background.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());

	//set and draw hit box
	ofFill();
	ofSetColor(0, 0, 0, 0);
	ofDrawRectangle(hitbox_x, hitbox_y, hitbox_width, hitbox_height);

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

	//draws wings up bird if falling
	//else draw wings down bird if flapping
	ofSetColor(255);
	if (bird_velocity > 0) {
		wings_up.draw(wings_up_x_pos, bird_y_position, wings_up_width, wings_up_height);
	}
	else {
		wings_down.draw(wings_down_x_pos, bird_y_position, wings_down_width, wings_down_height);
	}

	//draws score at top of screen
	ofSetColor(255);
	flappy_font.drawString(std::to_string(score), 450, 300);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (bird_is_dead == false) {
		switch (key) {
		case ' ':
			bird_flapped = true;
			flap_sound.play();
			break;
		}
	} else if (bird_is_dead && sound_played) {
		switch (key) {
		case ' ':
			reset();
			break;
		}
	}
}

//--------------------------------------------------------------
void ofApp::reset() {
	setup();
}

//--------------------------------------------------------------
void ofApp::flapAndFall() {
	//bird flap and fall
	if (bird_flapped && bird_is_dead == false) {
		bird_acceleration = 0.0f;
		bird_velocity = bird_flap_thrust;
		bird_flapped = false;
	}
	else {
		bird_acceleration += bird_gravity;
	}
}

//--------------------------------------------------------------
void ofApp::capAcceleration() {
	//cap acceleration at gravity
	if (bird_acceleration >= bird_gravity) {
		bird_acceleration = bird_gravity;
	}
}

//--------------------------------------------------------------
void ofApp::updateBirdAndHitbox() {
	//update bird and hitbox vertical position if above ground barrier
	if (bird_y_position < ground_barrier) {
		bird_velocity += bird_acceleration;
		bird_y_position += bird_velocity;
		hitbox_y += bird_velocity;
	}
	else {
		bird_is_dead = true;
		if (sound_played == false) {
			die.play();
			sound_played = true;
		}
	}
}

//--------------------------------------------------------------
void ofApp::scrollPipes() {
	//level scrolling for pipes
	if (bird_is_dead == false) {
		pipe1_position -= 1.0f;
		pipe2_position -= 1.0f;
		pipe3_position -= 1.0f;
	}
	if (pipe1_position < 0 && bird_is_dead == false) {
		pipe1_height = ofRandom(200, 800);
		pipe1_position = 1210;
	}
	else if (pipe2_position < 0 && bird_is_dead == false) {
		pipe2_height = ofRandom(200, 800);
		pipe2_position = 1210;
	}
	else if (pipe3_position < 0 && bird_is_dead == false) {
		pipe3_height = ofRandom(200, 800);
		pipe3_position = 1210;
	}
}

//--------------------------------------------------------------
void ofApp::hitDetectionPipe1() {
	//hit detection for pipe1
	if ((hitbox_x + hitbox_width) >= (pipe1_position - pipe_width) && (hitbox_x) <= (pipe1_position)) {
		if (hitbox_y <= (ground_height - pipe1_height - vert_pipe_space) || (hitbox_y + hitbox_height) >= (ground_height - pipe1_height)) {
			bird_is_dead = true;
			if (sound_played == false) {
				die.play();
				fall.play();
				sound_played = true;
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::hitDetectionPipe2() {
	//hit detection for pipe2
	if ((hitbox_x + hitbox_width) >= (pipe2_position - pipe_width) && (hitbox_x) <= (pipe2_position)) {
		if (hitbox_y <= (ground_height - pipe2_height - vert_pipe_space) || (hitbox_y + hitbox_height) >= (ground_height - pipe2_height)) {
			bird_is_dead = true;
			if (sound_played == false) {
				die.play();
				fall.play();
				sound_played = true;
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::hitDetectionPipe3() {
	//hit detection for pipe3
	if ((hitbox_x + hitbox_width) >= (pipe3_position - pipe_width) && (hitbox_x) <= (pipe3_position)) {
		if (hitbox_y <= (ground_height - pipe3_height - vert_pipe_space) || (hitbox_y + hitbox_height) >= (ground_height - pipe3_height)) {
			bird_is_dead = true;
			if (sound_played == false) {
				die.play();
				fall.play();
				sound_played = true;
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::passPipe() {
	//check for successful pass thorugh pipe
	if ((bird_x_position == pipe1_position - point_delay
		|| bird_x_position == pipe2_position - point_delay
		|| bird_x_position == pipe3_position - point_delay)
		&& bird_is_dead == false) {
		pipe_pass.play();
		score++;
	}
}