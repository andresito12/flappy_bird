4/17/18
Problems:
1) Running into issues about how to make the bird gravity work.

Solutions:
1) I've just decided to make it flap upwards on a key press and fall due to gravity.
I am also considering putting a cap on spamming the space bar until the velocity is positive and it begins to fall.

4/24/18
Problems:
1) Bird would reset location every time I wanted it to flap.
2) The bird was accelerating extremely quickly just by adding gravity to its current acceleration upon each update.
3) The bird would stop when pressing the space bar, then resume falling.
4) Problems committing progress since I made a new project and am trying to commit to the same repository.

Solutions:
1) I was setting my acceleration to 0 if the space bar was pressed. I then realized that I was drawing using position instead of acceleration each time it was drawn after space bar was pressed.
2) I added a cap to the acceleration of the bird by limiting it to gravity to make the bird easier to control.
3) I did not realize right away that the gravity was overpowering the upwards thrust, so I increased the multiplier for negative velocity.

4/25/18
Problems:
1) Getting load errors for flap sound for bird.
2) Getting unallocated errors for flappy bird jpg.
3) Problems committing progress since I made a new project and am trying to commit to the same repository.

Solutions:
1) I converted the mp3 files to wav files but I'm still having issues at the moment.
2) I tried using ofImage and ofTexture but I do not have either working yet.

1) I converted the mp3 files to wav files and moving them into different folders in case of scope problems but I'm still having issues at the moment.
2) I tried using ofImage and ofTexture but I do not have either working yet. I also tried moving them into different folders in case of scope problems.

4/29/18
Problems:
1) Issues committing and loading files

Solutions:
1) Completely reorganized my Visual Studio project and my Github repository to get reorganized and it fixed my issues with committing and loading files.

4/30/18
Problems:
1) My entire window kept turning green instead of my test pipe. 
2) My pipe would start at the bottom of the window instead of the ground in the background.
3) The vertical distance between the upper and lower test pipe was not consistent as it should have been.

Solutions:
1) I set the color to white before drawing and setting the pipe color to fix the issue.
2) I used a negative width and height to set the lower right-hand corner of the rectangle instead of the upper left-hand corner.
3) I sketched the pipe on graph paper to visualize what the x, y, width, and height should be for the upper and lower parts of the test pipe. I realized my problem was a positive/negative sign mix-up in my logic.

5/1/18
Problems:
1) Pipes would not be equally spaced when spawning.
2) Pipes were being distorted randomly when they showed up on screen.
3) Pipes were not appearing to slide into the window like they should have been.

Solutions:
1) Window resizing and experimented with different values for scroll speed and distance between pipes.
2) I realized that I was not spawning the pipes in the same location so they were drawing over each other.
3) I spawned them further off-screen so they would not draw within view.

5/2/18
Problems:
1) The bird would die after hitting an open space between pipes.
2) The sound effects were playing over each other infinitely in the update method.

Solutions:
1) The hitbox was not following the bird once the bird started moving. I just had to update the hitbox so it would follow the bird.
2) I added flags so the effects would only play once for each instance of the game. All the values would reset when the game would reset based on a space bar press.