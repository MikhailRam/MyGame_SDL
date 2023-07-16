#include <iostream>
#include <SDL2/SDL.h>

#include "Game.h"
#include "Protagonist.h"
#include "Enemy.h"

namespace window_parametrs{
    constexpr uint16_t delay_value{3000};

    constexpr char* game_Title{"Game"};
    constexpr int width{1280};
    constexpr int height{720};
}

void specify_OpenGL(SDL_Window* new_window){
    // Before we create our window, specify OpenGL version
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,24);

    SDL_GLContext context;
    context = SDL_GL_CreateContext(new_window);
}

int main() {
    Game* game = new Game();
    specify_OpenGL(game->get_window());
    game->init(window_parametrs::game_Title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                window_parametrs::width, window_parametrs::height, false);

    while(game->running()){
        game->handleEvents();
        game->update();
        game->render();
    }
    game->clean();

//    SDL_Delay(window_parametrs::delay_value);
    return 0;
}