#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
		const float x_position = ofGetWindowWidth() / 3;
		float y_position;
		float velocity;
		float acceleration;
		float gravity;
		float flap_thrust;
		bool flapped;
		double elapsed_time;

		ofImage background;

		ofImage wings_up;
		ofImage wings_down;
		ofSoundPlayer flap_sound;

		float pipe1_position;
		float pipe2_position;
		float pipe3_position;
		float pipe1_height;
		float pipe2_height;
		float pipe3_height;
		float horiz_pipe_space;
		float vert_pipe_space = 365.0f;
		const float pipe_width = 150;
		const float ground_height = ofGetWindowHeight() - 185;
		const float top_pipe_height = 1000.0f;
};
