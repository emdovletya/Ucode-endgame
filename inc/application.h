//
// Created by Rostyslav Druzhchenko on 04.05.2020.
//

#pragma once

#include <sdl_all.h>

typedef struct Application {
    SDL_Renderer *renderer;
    SDL_Window *window;
//    int left;
//    int right;
//    int quit;
} App;

App *get_application();
void destroy_application();
