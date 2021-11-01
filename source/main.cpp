#include <iostream>
#include <SDL2/SDL.h>

int main()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) > 0)
    {
        std::cout << "SDL_Init failed with error: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "Hello World!" << std::endl;
    return EXIT_SUCCESS;
}