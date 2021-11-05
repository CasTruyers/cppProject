#include "Game.hpp"
#include "Snake.hpp"
#include "Food.hpp"
#include "Resources.hpp"

Game *game = nullptr;

int main()
{
    int frameStart;
    int frameTime;

    game = new Game();

    game->init("snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, RESOLUTION_X, RESOLUTION_Y, false);

    while (game->running())
    {
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();

    return EXIT_SUCCESS;
}
