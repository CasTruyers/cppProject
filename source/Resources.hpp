#pragma once
#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <fstream>
#include "SDL2/SDL.h"
#include <time.h>

#define CELL_SIZE 8
#define RESOLUTION_Y 240
#define RESOLUTION_X 320

const int FPS = 18;
const int frameDelay = 1000 / FPS;

struct xy
{
    int8_t x;
    int8_t y;
};

using namespace std;

using std::cout;
using std::endl;
using std::fstream;
using std::ios_base;