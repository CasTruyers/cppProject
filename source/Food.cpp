#include "resources.hpp"
#include "Food.hpp"

Food::Food()
{
}

Food::~Food()
{
}

void Food::reset(snake *snake)
{
    srand((unsigned int)time(NULL));
    bool found = false;
    while (!found)
    {
        position.x = rand();
        position.y = rand();

        found = true;
        for (int i = 0; i < snake->length; i++)
        {
            if (snake->position[i].x == position->x && snake->position[].y == position.y)
            {
                found = false;
            }
        }
    }
}
void Food::render()
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    for (int i = 1; i = < length; i++) 
    {
        SDL_RenderDrawRects(renderer, &this->rectangle[i]);
    }
}