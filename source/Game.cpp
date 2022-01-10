#include "Game.hpp"

Game::Game()
{
    snake = new Snake();
    food = new Food();
    food->reset(snake);

    snake->setLength(5);
    highscore = snake->getLength();
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
    SDL_RenderSetLogicalSize(renderer, width / cellSize, height / cellSize);
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
            break;
        case SDLK_DOWN:
            snake->goDown();
            break;
        case SDLK_LEFT:
            snake->goLeft();
            break;
        case SDLK_RIGHT:
            snake->goRight();
            break;
        case SDLK_RETURN:
            this->reset();
            break;
        case SDLK_ESCAPE:
            isRunning = false;
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
    }

    if (snake->badCollision())
    {
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
    if (snake->getLength() > highscore)
        highscore = snake->getLength();
    cout << "score: " << +snake->getLength() << endl
         << "highScore: " << highscore << endl;
    snake->reset();
    food->reset(snake);
}

void Game::setHighscore(char *name)
{
    int i;
    string input;
    myFile.open("highscore.txt", ios::in);
    if (myFile.is_open())
    {
        getline(myFile, input);
        myFile.close();
        for (i = 0; i <= input.size(); i++)
        {
            if (input[i] == ':')
                break;
        }
        string score = input.substr(i + 1, 3);
        string leader = input.substr(0, i);
        stringstream number(score);
        number >> allTimeHighscore;

        printAllTimeHighscore(allTimeHighscore, leader);
        if (allTimeHighscore < highscore || allTimeHighscore == 0)
        {
            printNewAllTimeHighscore(highscore, name);
            myFile.open("highscore.txt", ios::out);
            if (myFile.is_open())
            {
                myFile << name << ":" << highscore;
                myFile.close();
            }
            else
                cout << "Error opening file output" << endl;
        }
        else
            cout << "* did not break highscore :( *" << endl;
        cout << "*                            *" << endl
             << "******************************" << endl;
    }
    else
    {
        cout << "Error opening file input" << endl;
    }
}
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << endl
         << "game cleared" << endl;
}

void Game::printAllTimeHighscore(int &value, string leader)
{
    cout << endl
         << endl
         << "******************************" << endl
         << "*                            *" << endl
         << "*   all-time highscore: " << value << "   *" << endl
         << "* held by: " << leader << endl
         << "*                            *" << endl;
}

void Game::printNewAllTimeHighscore(int &value, char *name)
{
    cout << "*     breaked highscore!     *" << endl
         << "*                            *" << endl
         << "* new all-time highscore: " << value << " *" << endl
         << "* On name: " << name << endl;
}