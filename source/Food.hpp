#pragma once
#include "Resources.hpp"
#include "Snake.hpp"

class Food : Snake
{
public:
    Food();
    ~Food();

    void reset(Snake *snake);
    void render(SDL_Renderer *renderer);

    SDL_Rect position;

private:
};