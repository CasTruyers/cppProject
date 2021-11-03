#include "Game.hpp"

Game *game = nullptr;

int main()
{
    const int FPS = 24;
    const int frameDelay = 1000 / FPS;

    int frameStart;
    int frameTime;

    game = new Game();

    game->init("snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, wWidth, wHeight, false);

    game->setRectangle(wWidth / 2, wHeight / 2, snakeSize, snakeSize);

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
