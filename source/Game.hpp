#pragma once
#include "Snake.hpp"
#include "Food.hpp"
#include "Resources.hpp"

class Game
{
public:
    Game();
    ~Game();

    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();
    bool running() { return isRunning; }
    void setRectangle(int xpos, int ypos, int w, int h);

    void reset();

    Snake *snake;
    Food *food;

    SDL_Renderer *renderer = nullptr;

private:
    int highScore;
    bool isRunning;
    SDL_Window *window = nullptr;
};