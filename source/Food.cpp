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
        this->position.x = rand() % RESOLUTION_X / CELL_SIZE;
        this->position.y = rand() % RESOLUTION_Y / CELL_SIZE;
        cout << "foodPos: " << this->position.x << ", " << this->position.y << endl;
        found = true;
        for (int i = 0; i < snake->length; i++)
        {
            if (snake->position[i].x == this->position.x && snake->position[i].y == this->position.y)
            {
                found = false;
            }
        }
    }
}
void Food::render(SDL_Renderer *renderer) //acces game class for renderer?
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &this->position);
}