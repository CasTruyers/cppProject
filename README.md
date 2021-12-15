# SNAKE GAME

**a long, thin creature, resembling a snake**

## DESCRIPTION

### snake

The player controls a snake, which roams around on
a bordered plane, picking up food, trying to avoid hitting its own tail
or the edges of the playing area. Each time
the snake eats a piece of food, its tail grows
longer, making the game increasingly
difficult. The user controls the direction of
the snake's head (up, down, left, or right),
and the snake's body follows.

### language

The application is entirely written in C++.

### graphics

SDL2 library is used to acces the hardware on the computer. (i.e. display, keyboard,...)

This application talks to the graphics card to render graphics, and the keyboard to take user input.

**SDL2 works cross-platform!**

### FEATURES

- All snake game logic
- A graphical display
- Writing the highscore to a .txt file and updating it whenever its beated

### HOW TO INSTALL

Clone the repository and make sure you have the SDL2 library.

Add include folder with the header files of the SDL2 library.

Add lib folder with the binary files of the SDL2 library.

### HOW TO COMPILE

while compiling:
use -Iinclude for linking the headers
use -Llib for linking the binary files
use -lsd12
add all source/_.cpp_ files

**example:**
_g++ -std=c++11 -Wall -g -lsdl2 -Iinclude -Llib source/Food.cpp source/Game.cpp source/Main.cpp source/Snake.cpp -o build/snake_

### HOW TO USE

Run the application, a window pops up and the game begins.

Use the UP, DOWN, LEFT and RIGHT keys on the keyboard to control the snake.

Quit the game be closing the window or pressing ESC.

### TO-DO

- sounds
- memory optimization
- score/highscore displayed on window
