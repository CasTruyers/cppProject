#include <iostream>
#include <SDL2/SDL.h>

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 320, 240, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_Event event;
    SDL_PollEvent(&event);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_Delay(10000);

    return EXIT_SUCCESS;
}