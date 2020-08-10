//
// Created by Rostyslav Druzhchenko on 06.05.2020.
//

#pragma once

#include <hero.h>
#include "header.h"

typedef struct s_level {
    t_hero *hero;
    Mix_Music *current_song;
    SDL_Renderer *renderer;
    t_sprite background;
}              t_level;

t_level *create_level(SDL_Renderer *renderer);
void destroy_level(t_level **level);
