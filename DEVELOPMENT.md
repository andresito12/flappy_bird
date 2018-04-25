4/18/18
Problems:
1) Running into issues about how to make the bird gravity work.

Solutions:
1) I've just decided to make it flap upwards on a key press and fall due to gravity.
I am also considering putting a cap on spamming the space bar until the velocity is positive and it begins to fall.

4/24/18
Problems:
1) Bird would reset location everytime I wanted it to flap.
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
2) Problems committing progress since I made a new project and am trying to commit to the same repository.

Solutions:
1) I converted the mp3 files to wav files but I'm still having issues at the moment.
