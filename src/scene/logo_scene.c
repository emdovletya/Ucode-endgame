//
// Created by Rostyslav Druzhchenko on 04.05.2020.
//

#include <sdl_all.h>
#include <header.h>

void present_logo_scene() {
    SDL_Event event;
    SDL_Renderer *renderer = get_application()->renderer;
    SDL_Rect rc_logo = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
    SDL_Texture *logo = IMG_LoadTexture(renderer, MX_RES("logo.png"));

    while (1) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYUP) {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                    case SDLK_RETURN:
                    case SDLK_SPACE:
                        SDL_DestroyTexture(logo);
                        return;
                    case SDLK_q:
                        exit(0);
                    default:
                        break;
                }
            }
        }
        SDL_RenderCopy(renderer, logo, NULL, &rc_logo);
        usleep(100);
        SDL_RenderPresent(renderer);
    }
}
