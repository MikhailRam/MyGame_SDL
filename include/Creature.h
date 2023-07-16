//
// Created by Mikhail Ramzhaev on 11.07.23.
//
#ifndef MYGAME_СREATURE_H
#define MYGAME_СREATURE_H

#include "SDL2_image/SDL_image.h"
#include <string>

class Creature{
public:
    Creature();
    virtual ~Creature() = default;

    virtual void creature_init(SDL_Renderer* new_renderer) = 0;

    SDL_Texture* get_creature_texture(){return creature_texture;}

private:

protected:
    SDL_Texture* creature_texture;



};

#endif //MYGAME_СREATURE_H