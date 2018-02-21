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
  
  so [0] -> [0][0]
     [1] -> [0][1]
          :
     [5] -> [1][4]
     [6] -> [1][3]
     
