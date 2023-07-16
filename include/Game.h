//
// Created by Mikhail Ramzhaev on 16.07.23.
//

#ifndef MYGAME_GAME_H
#define MYGAME_GAME_H

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "Protagonist.h"

class Game{
public:
    Game();
    ~Game() = default;

    void init(const char* title, int x_pos, int y_pos,
              int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();

    SDL_Window* get_window(){
        return window;
    }

    bool running() {return isRunning;}
private:
    bool isRunning;
    int cnt = 0;
    SDL_Window *window;
    SDL_Renderer *renderer;
};

#endif //MYGAME_GAME_H
