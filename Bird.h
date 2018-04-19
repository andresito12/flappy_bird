
using namespace std;

class Bird {
public:
	Bird(float groundHeight);

	void update(double time);
	void draw(double time);

	void flap();
	void die();
	void reset();
	void pause();
	void resume();
	bool hasCrashed() const;

private:
	const static float flapSpeed, maxSpeed, gravity;
};