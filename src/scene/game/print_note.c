#include "header.h"

void print_notes(App *app, t_notes *note, int lives) {
    if (lives > 0) {
        SDL_RenderCopy(app->renderer, note->nota.texture, NULL, &note->nota.n_1);
        SDL_RenderCopy(app->renderer, note->nenota.texture, NULL,
                       &note->nenota.n_1);
        SDL_RenderCopy(app->renderer, note->nota.texture, NULL, &note->nota.n_2);
        SDL_RenderCopy(app->renderer, note->nenota.texture, NULL,
                       &note->nenota.n_2);
        SDL_RenderCopy(app->renderer, note->nota.texture, NULL, &note->nota.n_3);
        SDL_RenderCopy(app->renderer, note->nenota.texture, NULL,
                       &note->nenota.n_3);
    }
}
