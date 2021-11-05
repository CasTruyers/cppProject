#pragma once
#include <stdio.h>
#include <iostream>
#include "SDL2/SDL.h"
#include <time.h>

#define CELL_SIZE 5
#define RESOLUTION_Y 240
#define RESOLUTION_X 320

const int FPS = 24;
const int frameDelay = 1000 / FPS;

struct xy
{
    int x;
    int y;
};

using std::cout;
using std::endl;