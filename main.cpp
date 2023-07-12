#include <iostream>
#include <SDL2/SDL.h>

#include "Protagonist.h"
#include "Enemy.h"


namespace window_parametrs{
    constexpr uint16_t delay_value{3000};

    constexpr uint16_t width_pix{3000};
    constexpr uint16_t hight_pix{2000};
    constexpr uint16_t width{1280};
    constexpr uint16_t hight{720};
}

int main() {

    SDL_Window* window {nullptr};
    SDL_Surface* screenSurface{nullptr};

    // Initialize the video subsystem.
    // If it returns less than 1, then an
    // error code will be received.
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "SDL could not be initialized: " <<
                  SDL_GetError();
    }else{
        std::cout << "SDL video system is ready to go\n";
    }
    // Before we create our window, specify OpenGL version
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,24);

    // Request a window to be created for our platform
    // The parameters are for the title, x and y position,
    // and the width and height of the window.
    window = SDL_CreateWindow("C++ SDL2 Window",
                              window_parametrs::width_pix,
                              window_parametrs::hight_pix,
                              window_parametrs::width,
                              window_parametrs::hight,
                              SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    // OpenGL setup the graphics context
    SDL_GLContext context;
    context = SDL_GL_CreateContext(window);

    // Setup our function pointers

    // Infinite loop for our application
    bool gameIsRunning = true;
    while(gameIsRunning){

        SDL_Event event;
        // Start our event loop
        while(SDL_PollEvent(&event)){
            // Handle each specific event
            if(event.type == SDL_QUIT){
                gameIsRunning= false;
            }
            if(event.type == SDL_MOUSEMOTION){
                std::cout << "mouse has been moved\n";
            }
            if(event.type == SDL_KEYDOWN){
                std::cout << "a key has been pressed\n";
                if(event.key.keysym.sym == SDLK_0){
                    std::cout << "0 was pressed\n";
                }else{
                    std::cout << "0 was not pressed\n";
                }
            }
            // Retrieve the state of all of the keys
            // Then we can query the scan code of one or more
            // keys at a time
            const Uint8* state = SDL_GetKeyboardState(nullptr);
            if(state[SDL_SCANCODE_RIGHT]){
                std::cout << "right arrow key is pressed\n";
            }
        }

        SDL_GL_SwapWindow(window);
    }

    // We destroy our window. We are passing in the pointer
    // that points to the memory allocated by the
    // 'SDL_CreateWindow' function. Remember, this is
    // a 'C-style' API, we don't have destructors.
    SDL_DestroyWindow(window);

    // We safely uninitialize SDL2, that is, we are
    // taking down the subsystems here before we exit
    // We add a delay in order to see that our window
    // has successfully popped up.
    SDL_Delay(window_parametrs::delay_value);
    // We add a delay in order to see that our window
    // has successfully popped up.
    SDL_Delay(window_parametrs::delay_value);
    // We add a delay in order to see that our window
    // has successfully popped up.
    SDL_Delay(window_parametrs::delay_value);
    // We add a delay in order to see that our window
    // has successfully popped up.
    SDL_Delay(window_parametrs::delay_value);
    // We add a delay in order to see that our window
    // has successfully popped up.
    SDL_Delay(window_parametrs::delay_value);
    // our program.
    SDL_Quit();
    return 0;
}