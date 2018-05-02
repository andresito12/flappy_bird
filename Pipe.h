#pragma once

#include "ofMain.h"

class Pipe : public ofBaseApp {

public:
	list<int> pipes{ 0, 0, 0 };
	float level_position;
	float section_width;
	float horiz_pipe_space;
	float vert_pipe_space;
	int current_section;
};