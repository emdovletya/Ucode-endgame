#include "header.h"

int show_players(SDL_Renderer *renderer) {
    SDL_Rect about_rect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
    SDL_Texture *img_about = IMG_LoadTexture(renderer, MX_RES("players.png"));

    SDL_Event event;
    while (1) {
        SDL_RenderCopy(renderer, img_about, NULL, &about_rect);
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYUP) {
                if (event.key.keysym.sym == SDLK_ESCAPE 
                    || event.key.keysym.sym == SDLK_SPACE 
                    || event.key.keysym.sym == SDLK_q
                    || event.key.keysym.sym == SDLK_RETURN) {
                    return 6;
                }
            }
        }
        usleep(10000);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(img_about);
    return 1;
}
