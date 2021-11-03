#pragma once

#include <stdio.h>
#include <iostream>
#include "SDL2/SDL.h"

#define snakeSize 5
#define wHeight 240
#define wWidth 320

using std::cout;
using std::endl;

class Game
{
public:
    Game();
    ~Game();

    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();
    bool running() { return isRunning; }
    void setRectangle(int xpos, int ypos, int w, int h);

private:
    int offsetx = 0;
    int offsety = 0;
    bool isRunning;
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_Rect rectangle;
};