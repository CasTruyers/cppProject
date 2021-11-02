#include "Game.hpp"

Game::Game()
{
}

Game::~Game()
{
}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        cout << "Subsystems initialised!..." << endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window)
        {
            cout << "Window Created" << endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            cout << "Renderer Created" << endl;
        }

        isRunning = true;
    }
    else
    {
        isRunning = false;
    }
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;

    case SDL_KEYDOWN:
        cout << "keyPresssed" << endl;

        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            cout << "UP" << endl;
            break;
        case SDLK_DOWN:
            cout << "DOWN" << endl;
            break;
        case SDLK_LEFT:
            cout << "LEFT" << endl;
            break;
        case SDLK_RIGHT:
            cout << "DOWN" << endl;
            break;

        case SDLK_a:
            cout << "a" << endl;
            break;

        default:
            break;
        }
        break;
    default:
        break;
    }
}

void Game::update()
{
    cnt++;
    cout << cnt << endl;
}

void Game::render()
{
    SDL_RenderClear(renderer);
    //here add stuff to render
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "game cleared" << endl;
}