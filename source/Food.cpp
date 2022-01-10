#include "Food.hpp"
#include "Game.hpp"

Food::Food()
{
    this->position.h = 1;
    this->position.w = 1;
}

Food::~Food()
{
}

void Food::reset(Snake *snake)
{
    srand((unsigned int)time(NULL));
    bool found = false;
    while (!found)
    {
        this->position.x = rand() % width / cellSize;
        this->position.y = rand() % height / cellSize;
        found = true;

        //checkt of food zich niet op de zelfde pixel als de snake bevindt
        for (int i = 0; i < getLength(); i++) //inheretance: getLength() is van snake class
        {
            if (snake->position[i].x == this->position.x && snake->position[i].y == this->position.y)
                found = false;
        }
    }
}
void Food::render(SDL_Renderer *renderer) //acces game class for renderer?
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &this->position);
}