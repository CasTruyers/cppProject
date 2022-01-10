#pragma once
#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <fstream>
#include "SDL2/SDL.h"
#include <time.h>
#include <sstream>

static const uint8_t cellSize = 8;
static const uint8_t height = 240;
static const uint8_t width = 240;
static const uint8_t FPS = 18;
static const uint8_t frameDelay = 1000 / FPS;

typedef struct xy
{
    int8_t x;
    int8_t y;
} xy;

using namespace std;