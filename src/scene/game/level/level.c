//
// Created by Rostyslav Druzhchenko on 06.05.2020.
//

#include <level.h>
#include <stdlib.h>

t_level *create_level(SDL_Renderer *renderer) {
    t_level *level = (t_level *) malloc(sizeof(t_level));
    level->renderer = renderer;
    level->hero = create_hero(renderer);

    return level;
}

void destroy_level(t_level **level) {
    destroy_hero(&((*level)->hero));
    free(*level);
    *level = 0;
}
