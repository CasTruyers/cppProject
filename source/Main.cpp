#include "Game.hpp"

Game *game = nullptr;

int main()
{
    game = new Game();

    game->init("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 320, 240, false);

    while (game->running())
    {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();

    return EXIT_SUCCESS;
}
