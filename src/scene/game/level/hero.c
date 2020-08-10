//
// Created by Rostyslav Druzhchenko on 06.05.2020.
//

#include <hero.h>
#include <header.h>

t_hero *create_hero(SDL_Renderer *renderer) {
    t_hero *hero = (t_hero *) malloc(sizeof(t_hero));
    hero->is_moving = 0;
    hero->texture = IMG_LoadTexture(renderer, MX_RES("player.png"));

    SDL_QueryTexture(hero->texture, NULL, NULL, &hero->rect.w, &hero->rect.h);
    hero->rect.w /= 4;
    hero->rect.h /= 4;
    hero->rect.x = (WINDOW_WIDTH - hero->rect.w) / 2;
    hero->rect.y = (WINDOW_WIDTH - hero->rect.w) * 2;

    return hero;
}

void destroy_hero(t_hero **hero) {
    SDL_DestroyTexture((*hero)->texture);
    free(*hero);
    *hero = 0;
}
