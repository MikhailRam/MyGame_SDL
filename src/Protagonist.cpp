//
// Created by Mikhail Ramzhaev on 11.07.23.
//
#include "Protagonist.h"

Protagonist::Protagonist() {
    rect_cover.x = 0;
    rect_cover.y = 0;
    rect_cover.w = 192/2;
    rect_cover.h = 288/2;
}

void Protagonist::creature_init(SDL_Renderer* new_renderer)
{
    SDL_Surface* tmp_surface = IMG_Load(protagonist_img);
    creature_texture = SDL_CreateTextureFromSurface(new_renderer, tmp_surface);
    SDL_FreeSurface(tmp_surface);
}