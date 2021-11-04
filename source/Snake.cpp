#include "Snake.hpp"
#include "resources.hpp"

void Snake::reset()
{
    length = 5;
    direction.x = 1;
    direction.y = 0;

    for (int i = 0; i < length; i++)
    {
        position[i].x = 10 - i;
        position[i].y = 10;
    }
}

void Snake::goUp()
{
    if (direction.y == 0)
    {
        direction.x = 0;
        direction.y = -1;
    }
}

void Snake::goDown()
{
    if (direction.y == 0)
    {
        direction.x = 0;
        direction.y = 1;
    }
}

void Snake::goLeft()
{
    if (direction.x == 0)
    {
        direction.x = -1;
        direction.y = 0;
    }
}

void Snake::goRight()
{
    if (direction.x == 0)
    {
        direction.x = 1;
        direction.y = 0;
    }
}

void Snake::advance()
{
    for (int i = length - 1; i > 0; i--)
    {
        position[i].x = position[i - 1].x;
        position[i].y = position[i - 1].y;
    }
    position[0].x = position[0].x + direction.x;
    position[0].y = position[0].y + direction.y;
}

void Snake::selfCollision()
{
    for (int i = 1; i < length; i++)
    {
        if (position[0].x == position[i].x && position[0].y == position[i].y)
        {
            return true;
        }
    }
    if (position[0].x < 0)
        return true;
    if (position[0].y < 0)
        return true;
    if (position[0].x >= RESOLUTION_X / CELL_SIZE)
        return true;
    if (position[0].y >= RESOLUTION_Y / CELL_SIZE)
        return true;

    return false;
}

bool Snake::foodCollision(int x, int y)
{
    if (position[0].x == x && position[0].y == y)
    {
        return true;
    }
    return false;
}

void Snake::grow()
{
    this->rectangle[length].x = this->rectangle[length - 1].x;
    this->rectangle[length].y = this->rectangle[length - 1].y;
    length++
}

void Snake::render()
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    for (int i = 1; i = < length; i++) {SDL_RenderDrawRects(renderer, &this->rectangle[i]);}
}
