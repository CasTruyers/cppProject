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
    bool badCollision();
    bool foodCollision(int x, int y);
    void grow();
    void render(SDL_Renderer *renderer);

    void reset();

    SDL_Rect position[255]; //!dynamic maken
    uint8_t length;

private:
    struct xy direction;
};