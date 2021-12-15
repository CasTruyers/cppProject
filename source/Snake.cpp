#include "Game.hpp"
#include "Snake.hpp"

Snake::Snake()
{
    reset();
}

Snake::~Snake()
{
}

void Snake::reset()
{
    length = 5;
    //position = (SDL_Rect *)calloc(length, sizeof(SDL_Rect));
    direction.x = 1;
    direction.y = 0;

    for (int i = 0; i < length; i++)
    {
        position[i].x = 10 - i;
        position[i].y = 10;
        position[i].h = 1;
        position[i].w = 1;
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
    //body
    for (int i = length - 1; i > 0; i--)
    {
        position[i].x = position[i - 1].x;
        position[i].y = position[i - 1].y;
    }
    //head
    position[0].x = position[0].x + direction.x;
    position[0].y = position[0].y + direction.y;
}

bool Snake::badCollision()
{
    for (int i = 1; i < length; i++)
    {
        if (position[0].x == position[i].x && position[0].y == position[i].y)
            return true;
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
        return true;
    return false;
}

void Snake::grow()
{
    //position = (SDL_Rect *)realloc(position, ((length + 1) * sizeof(SDL_Rect)));
    //position = positionTemp;
    //free(positionTemp);

    //array is zero indexed.
    //[length - 1] is dus eigenlijk de laatste body en [length] de nieuwe
    this->position[length].h = 1;
    this->position[length].w = 1;
    this->position[length].x = this->position[length - 1].x;
    this->position[length].y = this->position[length - 1].y;
    length++;
}

void Snake::render(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    for (int i = 1; i < length; i++)
    {
        SDL_RenderDrawRect(renderer, &this->position[i]);
    }
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderDrawRect(renderer, &this->position[0]);
}
