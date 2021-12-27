#pragma once
#include "Snake.hpp"
#include "Food.hpp"
#include "Resources.hpp"

class Game
{
public:
    Game();
    ~Game();

    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen = false);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running() { return isRunning; }
    void setRectangle(int xpos, int ypos, int w, int h);
    void reset();
    void setHighscore();
    void printAllTimeHighscore(int &value);
    void printNewAllTimeHighscore(int &value);

private:
    int allTimeHighscore = 0; // int omdat fstream van uint8 een char maakt. Of voor mensen met heel hoge highscores.
    int highscore;            // geen uint8 door de zelfde reden als hierboven
    bool isRunning;
    fstream myFile;
    Snake *snake = nullptr;
    Food *food = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_Window *window = nullptr;
};