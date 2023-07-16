//
// Created by Mikhail Ramzhaev on 11.07.23.
//
#ifndef MYGAME_PROTAGONIST_H
#define MYGAME_PROTAGONIST_H

#include "Creature.h"

class Protagonist : public Creature{
public:
    Protagonist();
    ~Protagonist() = default;

    void creature_init(SDL_Renderer* new_renderer) override;
    SDL_Rect get_rect_cover(){return rect_cover;}
    SDL_Rect rect_cover;

private:
    const char* protagonist_img = "/Users/mikhailramzhaev/Documents/Works/Programming/CLion_Projects/MyGame/assets/Player.png";

};

#endif //MYGAME_PROTAGONIST_H
