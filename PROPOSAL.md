# Project Proposal: Flappy Bird
My final project is going to be an implementation of Flappy Bird. I was thinking that this would be a fun 2d game to try and recreate. 

Tasks:
1) I will need to randomly generate a gap between the pipes for the bird to fly through.
2) Have the pipes slide across the screen from right to left.
3) Update the score each time a pipe is successfully passed through
4) Handle vertical movement for bird
5) Possibly add aesthetics at the end for background
6) Sound effects for flaps and passing through pipes
7) Barrier recognition like that of snake to end game when bird hits pipe or ground
8) Display score after game ends

Possible Obstacles:
1) How gravity will work? I'm not how I am going to implement the movement of the bird. I could have it flap upwards each time a key is pressed. Another way would be to have it ascend until a key is pressed and then have it descend. Then it would descend until a key is pressed again. There would be no gravity at all in that implementation. Another possibility is to use the arrow keys to ascend and descend while they are pressed. There would be no gravity here either because the bird would float at its current position until it is moved.
2) Using snake to recognize moving pipes so game ends when bird crashes into ground or pipe.

Libraries: 
ofImage to load background and bird images
http://openframeworks.cc/documentation/graphics/ofImage/
ofSoundPlayer to load sound effects
http://openframeworks.cc/documentation/sound/ofSoundPlayer/
ofTrueTypeFont to load font from original flappy bird game
http://openframeworks.cc/documentation/graphics/ofTrueTypeFont/