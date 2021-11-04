#pragma once
#include "resources.hpp"

#define CELL_SIZE 5

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
    bool foodCollision();
    void grow();

    void reset();

private:
    int length;
    struct xy direction;
};