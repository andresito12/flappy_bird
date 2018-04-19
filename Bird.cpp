#include "Bird.h"
#include <Texture2D.h>

using namespace std;

const float Bird::flapSpeed = -500.0f;
const float Bird::maxSpeed = 750.0f;
const float Bird::gravity = 1500.0f;

Bird::Bird(float ground_height): speed(0.0f), ground(ground_height) {
	std::flappy_bird = ">>\\\\O>";
	Window* window = Game::instance()->window;
	float x = window->getWidth() / 5.0f;
	float y = window->getHeight() / 2.0f;
	bounds.width = 2.5f * flappy_bird->width;
	bounds.height = 2.5f * flappy_bird->height;
	bounds.x = x - bounds.width / 2.0f;
	bounds.y = y - bounds.height / 2.0f;
	starting_position = bounds.topLeft();
}

Bird::~Bird() {
	delete flappy_bird;
}

void Bird::update(double time) {
	speed += gravity * time / 2.0f;
	if (speed > maxSpeed) {
		speed = maxSpeed;
	}
	bounds.y += speed * time;
	speed += gravity * time / 2.0f;
	if (bounds.top() < 0.0f) {
		bounds.y = 0.0f;
	}
	if (bounds.bottom() >= ground) {
		die();
		bounds.y = ground - bounds.height + 2.5f;
	}
}

void Bird::draw(double time) {
	flappy_bird->draw(bounds);
}

void Bird::flap() {
	if (crashed) {
		return;
	}
	speed = flapSpeed;
}

void Bird::die() {
	crashed = true;
}

void Bird::reset() {
	bounds.x = starting_position.x;
	bounds.y = starting_position.y;
	speed = 0.0f;
	crashed = false;
}

bool Bird::hasCrashed() const {
	return crashed;
}

const Rectangle& Bird::getBounds() const {
	return bounds;
}
