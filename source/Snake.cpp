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
    for (int i = length - 1; i > 0; i--)
    {
        position[i].x = position[i - 1].x;
        position[i].y = position[i - 1].y;
    }
    position[0].x = position[0].x + direction.x;
    position[0].y = position[0].y + direction.y;
}

bool Snake::selfCollision()
{
    for (int i = 1; i < length; i++)
    {
        if (position[0].x == position[i].x && position[0].y == position[i].y)
        {
            cout << "test: 1" << endl;
            return true;
        }
    }
    if (position[0].x < 0)
    {
        cout << "test: 2" << endl;
        return true;
    }
    if (position[0].y < 0)
    {
        cout << "test: 3" << endl;
        return true;
    }
    if (position[0].x >= RESOLUTION_X / CELL_SIZE)
    {
        cout << "test: 4" << endl;
        return true;
    }
    if (position[0].y >= RESOLUTION_Y / CELL_SIZE)
    {
        cout << "test: 5" << endl;
        return true;
    }

    return false;
}

bool Snake::foodCollision(int x, int y)
{
    if (position[0].x == x && position[0].y == y)
    {
        cout << "yum" << endl;
        return true;
    }
    return false;
}

void Snake::grow()
{ //!fix dit
    this->position[length].x = this->position[length - 1].x;
    this->position[length].y = this->position[length - 1].y;
    length++;
}

void Snake::render(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    for (int i = 0; i < length; i++)
    {
        SDL_RenderDrawRect(renderer, &this->position[i]);
    }
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderDrawRect(renderer, &this->position[0]);
}
