# so_long

Creation of my own 2D game in which a spaceship invades planets and leaves through a black hole.

I used a basic graphical library called MiniLibX (based on the X11 library) developed for students and provided by 42 Vienna.

The player’s goal is to collect every collectible present on the map, then escape chosing the shortest possible route.  
• The W, A, S, and D keys must be used to move the main character (arrow keys or mouse buttons also work)  
• The player should be able to move in these 4 directions: up, down, left, right  
• The player should not be able to move into walls  
• At every move, the current number of movements must be displayed in the shell (also displayed on map)  
• The player has to be able to reach all collectibles  
• There can only be 1 player and 1 exit, there has to be at least 1 collectible  

The game should only run with correct maps used as input.  
The map can be composed of only these 5 characters:  
0 for an empty space  
1 for a wall  
C for a collectible  
E for a map exit  
P for the player’s starting position  

<img src="https://github.com/cyberKev42/so_long/blob/main/so_long/so_long_gameplay.gif" width="800" height="400"/>
