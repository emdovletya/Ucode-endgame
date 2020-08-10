#include "header.h"

static void mx_printerror(char *str) {
    write(2, "endgame: ", 9);
    for (int i = 0; str[i] != '\0'; i++)
        write(2, &str[i], 1);
    write(2, "\n", 1);
}

static void sdlerror(void) {
    mx_printerror((char *) SDL_GetError());
    exit(2);
}

void create_notes(App *app, t_notes *note) {
    if ((note->nota.srf = IMG_Load(MX_RES("nota.png"))) == NULL)
        sdlerror();
    if ((note->nenota.srf = IMG_Load(MX_RES("nenota.png"))) == NULL)
        sdlerror();
    note->nota.texture = SDL_CreateTextureFromSurface(
            app->renderer, note->nota.srf);
    note->nenota.texture = SDL_CreateTextureFromSurface(
            app->renderer, note->nenota.srf);
    SDL_FreeSurface(note->nota.srf);
    SDL_FreeSurface(note->nenota.srf);
    SDL_QueryTexture(note->nota.texture, NULL, NULL, &(note->nota.n_1.w),
                     &(note->nota.n_1.h));
    SDL_QueryTexture(note->nenota.texture, NULL, NULL, &(note->nenota.n_1.w),
                     &note->nenota.n_1.h);
    SDL_QueryTexture(note->nota.texture, NULL, NULL, &note->nota.n_2.w,
                     &note->nota.n_2.h);
    SDL_QueryTexture(note->nenota.texture, NULL, NULL, &note->nenota.n_2.w,
                     &note->nenota.n_2.h);
    SDL_QueryTexture(note->nota.texture, NULL, NULL, &note->nota.n_3.w,
                     &note->nota.n_3.h);
    SDL_QueryTexture(note->nenota.texture, NULL, NULL, &note->nenota.n_3.w,
                     &note->nenota.n_3.h);
}
