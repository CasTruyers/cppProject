#include "Game.hpp"
#include "Snake.hpp"
#include "Food.hpp"
#include "Resources.hpp"
//#include "SDL2/SDL_image.h"
//#include "SDL2/SDL_ttf.h"

Game *game = nullptr;

int main()
{
    int frameStart;
    int frameTime;

    game = new Game();

    //IMG_Init(IMG_INIT_JPG);
    //TTF_Init();

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

    game->setHighscore();

    game->clean();

    return EXIT_SUCCESS;
}
