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
 We use the SDL2 library to acces the hardware on our computer. (i.e. display, keyboard,...)
 In this case we talk to the graphics card to render graphics and to the keyboard to take user input.
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
 add all source/*.cpp* files
 
 **example:**
 *g++ -std=c++11 -Wall -g  -lsdl2 -Iinclude -Llib source/Food.cpp source/Game.cpp source/Main.cpp source/Snake.cpp -o build/snake*

### HOW TO USE
 Run the application, a window will pop up and the game begins.
 Use the UP, DOWN, LEFT and RIGHT keys on the keyboard to control the snake.

### TO-DO
 - File I/O for saving highscore
 - sounds
 - showing score and highscore on window instead of terminal
 - making SDL_Rect struct array dynamic
 - memory optimization
