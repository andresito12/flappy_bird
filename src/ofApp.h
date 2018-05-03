#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void gameOver();
	
		ofImage background;

		ofImage wings_up;
		ofImage wings_down;

		ofSoundPlayer flap_sound;
		ofSoundPlayer pipe_pass;
		ofSoundPlayer die;
		ofSoundPlayer fall;

		ofTrueTypeFont flappy_font;

		const float bird_x_position = ofGetWindowWidth() / 3;
		const float wings_up_x_pos = bird_x_position - 175;
		const float wings_down_x_pos = bird_x_position - 100;
		const float wings_up_width = 365.6f;
		const float wings_up_height = 205.6f;
		const float wings_down_width = 200.0f;
		const float wings_down_height = 205.6f;
		const float bird_gravity = .03f;
		const float bird_flap_thrust = -bird_gravity * 100;
		float bird_y_position;
		float bird_velocity;
		float bird_acceleration;
		bool bird_flapped;
		bool bird_is_dead;

		int score = 0;
		bool sound_played = false;

		const float horiz_pipe_space = 400.0f;
		const float vert_pipe_space = 365.0f;
		const float pipe_width = 150;
		const float top_pipe_height = 1000.0f;
		const float ground_height = ofGetWindowHeight() - 185;
		const float ground_barrier = ground_height - 140;
		const float point_delay = 150.0f;
		float pipe1_position;
		float pipe2_position;
		float pipe3_position;
		float pipe1_height;
		float pipe2_height;
		float pipe3_height;
		
		float hitbox_x = wings_down_x_pos + 50;
		float hitbox_y = bird_y_position + 50;
		const float hitbox_width = wings_down_width - 75;
		const float hitbox_height = wings_down_height - 120;
};
