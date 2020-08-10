#include "header.h"

void add_hero_lives_textures(SDL_Renderer *renderer, t_hearts *hearts) {
    hearts->full = IMG_LoadTexture(renderer, MX_RES("fullheart.png"));
    hearts->half = IMG_LoadTexture(renderer, MX_RES("halfheart.png"));
    hearts->empty = IMG_LoadTexture(renderer, MX_RES("emptyheart.png"));

    hearts->heart_pos1 = (SDL_Rect) {410, 25, 40, 40};
    hearts->heart_pos2 = (SDL_Rect) {360, 25, 40, 40};
    hearts->heart_pos3 = (SDL_Rect) {310, 25, 40, 40};
}
