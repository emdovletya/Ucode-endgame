//
// Created by Rostyslav Druzhchenko on 05.05.2020.
//

#pragma once

#include <stdbool.h>
#include <sdl_all.h>

enum e_direction {
    LEFT,
    RIGHT
};

typedef struct s_hero {
    enum e_direction direction;
    bool is_moving;
    SDL_Rect rect;
    SDL_Texture *texture;
}              t_hero;

t_hero *create_hero(SDL_Renderer *renderer);
void destroy_hero(t_hero **hero);
