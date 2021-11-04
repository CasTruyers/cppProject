#include "Game.hpp"

Game::Game()
{
    snake = new Snake();
    food = new Food();
    food->reset(snake);

    score = 5;
    highScore = score;
}

Game::~Game()
{
}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
        flags = SDL_WINDOW_FULLSCREEN;

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        cout << "Subsystems initialised!..." << endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window)
            cout << "Window Created" << endl;

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
            cout << "Renderer Created" << endl;

        isRunning = true;
    }
    else
        isRunning = false;
    SDL_RenderSetLogicalSize(renderer, RESOLUTION_X / CELL_SIZE, RESOLUTION_Y / CELL_SIZE);
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
        switch (event.key.keysym.sym)
        {

        case SDLK_UP:
            snake->goUp();
            cout << "UP" << endl;
            break;
        case SDLK_DOWN:
            snake->goDown();
            cout << "DOWN" << endl;
            break;
        case SDLK_LEFT:
            snake->goLeft();
            cout << "LEFT" << endl;
            break;
        case SDLK_RIGHT:
            snake->goRight();
            cout << "RIGTH" << endl;
            break;
        case SDLK_RETURN:
            this->reset();
            cout << "RESET" << endl;
            break;
        default:
            cout << "undefined KeyboardEvent" << endl;
            break;
        }
        break;

    default:
        break;
    }
}

void Game::update()
{
    snake->advance();

    if (snake->foodCollision(food->position.x, food->position.y))
    {
        food->reset(snake);
        snake->grow();
        score++;
        if (score > highScore)
        {
            highScore = score;
        }
        cout << "food collision" << endl;
    }

    if (snake->selfCollision())
    {
        cout << "self collision" << endl;
        reset();
    }
}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    snake->render(renderer);
    food->render(renderer);

    SDL_RenderPresent(renderer);
}

void Game::reset()
{
    snake->reset();
    food->reset(snake);

    cout << "score: " << score << endl
         << "highScore: " << highScore << endl;
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "game cleared" << endl;
}