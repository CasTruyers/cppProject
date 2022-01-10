#include "Game.hpp"
#include "Snake.hpp"
#include "Food.hpp"
#include "Resources.hpp"

int main(int argc, char **argv)
{
    int frameStart;
    int frameTime;

    Game *game = new Game();

    game->init("snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height);

    while (game->running())
    {
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);
    }

    game->clean();

    if (!strcmp(argv[1], "tournament") && argc == 3)
        game->setHighscore(argv[2]);

    return EXIT_SUCCESS;
}
