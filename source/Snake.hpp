#pragma once
#include "Resources.hpp"

class Snake
{
public:
    Snake();
    ~Snake();

    void advance();
    void goUp();
    void goDown();
    void goLeft();
    void goRight();
    bool selfCollision();
    bool foodCollision(int x, int y);
    void grow();
    void render(SDL_Renderer *renderer);

    void reset();

    SDL_Rect position[30];
    int length;

private:
    struct xy direction;
};