//
// Created by Mikhail Ramzhaev on 16.07.23.
//

#include "Game.h"

Protagonist* gamer_1 = new Protagonist;

Game::Game()
{}

void Game::init(const char* title, int x_pos, int y_pos, int width, int height, bool fullscreen)
{
    int flags = 0;

    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystems initialized! " << std::endl;
        window = SDL_CreateWindow(title, x_pos, y_pos, width, height,
                                  SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }
        isRunning = true;
    }

    gamer_1->creature_init(renderer);
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_MOUSEMOTION:
            std::cout << "mouse has been moved\n";
        case SDL_KEYDOWN:
            std::cout << "a key has been pressed\n";
            if (event.key.keysym.sym == SDLK_0) {
                std::cout << "0 was pressed\n";
            } else {
                std::cout << "0 was not pressed\n";
            }
    }
    const Uint8* state = SDL_GetKeyboardState(nullptr);
    if(state[SDL_SCANCODE_RIGHT]){
        gamer_1->rect_cover.x += 10;
//        gamer_1->rect_cover.y += 10;
    }
    if(state[SDL_SCANCODE_LEFT]){
        gamer_1->rect_cover.x -= 10;
//        gamer_1->rect_cover.y += 10;
    }
}

void Game::update()
{
    cnt++;
    std::cout << cnt << std::endl;
}

void Game::render()
{
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, gamer_1->get_creature_texture(),
                   NULL, &gamer_1->rect_cover);

    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;

}
