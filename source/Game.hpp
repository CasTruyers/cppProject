#pragma once
#include "Snake.hpp"
#include "Food.hpp"
#include "Resources.hpp"

#define RESOLUTION_Y 240
#define RESOLUTION_X 320

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

private:
    Snake *snake;
    Food *food;
    int score; //snakeLength
    int highScore;
    int offsetx = 0;
    int offsety = 0;
    bool isRunning;
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

protected:
    SDL_Rect rectangle[30];
};