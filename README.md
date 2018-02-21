# CloudLamp
Light Control for diy cloud lamp

Indexing into grid from string

Goal is to index into an array of LEDs like below:

2 *-*-*-*-*
  |
1 *-*-*-*-*
          |
0 *-*-*-*-*
  0 1 2 3 4
  
  When they are actually in a string like:
  
  0 1 2 3 4 ...                   15
  *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
  
      y  x      i
  so [0][0] -> [0]
     [0][1] -> [1]
          :
     [1][4] -> [5]
     [1][3] -> [6]
          :
     [2][4] -> [14]

if(y % 2)
  i = y * width + (width - 1 - x)
else
  i = y * width + x
  
Update Methods:
Sine Wave One Color
set update interval (this is the period)
each tick, update each light's progress(stagger init values to create patterns)
127 * sin(progress/interval * pi) + 127 is one option for update.

Gradient Sine Wave
Similar to above but we have to vary the percentage of the color that is one color or another. Red-Green gradient for instance needs to vary from 100% red to 50/50 to 100% green and back



