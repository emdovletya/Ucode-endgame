#include <hero.h>
#include "header.h"

int init_random(int low, int high) {
    int range = high - low;
    return (int) ((rand() / (float) (RAND_MAX)) * range) + low;
}


SDL_Rect set_coordinate(SDL_Rect rct, int speed) {
    // если больше 518у то начни с начала, двигайся со скоростю 4
    rct.y = (rct.y + rct.h >= 518) ? 0 : rct.y + speed;
    if (rct.y == 0)
        rct.x = init_random(0, 750);
    return (rct);
}

bool compare(SDL_Rect a, SDL_Rect b) {
    bool x = 0;
    bool y = 0;

    if (a.x <= b.x && a.x + a.w >= b.x)
        x = 1;
    if (a.x >= b.x && a.x + a.w <= b.x + b.w)
        x = 1;
    if (a.x <= b.x + b.w && a.x + a.w >= b.x + b.w)
        x = 1;
    if (a.y <= b.y && a.y + a.h >= b.y)
        y = 1;
    if (a.y >= b.y && a.y + a.h <= b.y + b.h)
        y = 1;
    if (a.y <= b.y + b.h && a.y + a.h >= b.y + b.h)
        y = 1;
    if (x == 1 && y == 1)
        return 1;
    return 0;
}

void note_falling(t_notes *note) {
    if (note->step == 1) {
        // is_catch_note(note);

        note->nota.n_1 = set_coordinate(note->nota.n_1, 4);
        note->nenota.n_1 = set_coordinate(note->nenota.n_1, 4);

        note->nota.n_2 = set_coordinate(note->nota.n_2, 6);
        note->nenota.n_2 = set_coordinate(note->nenota.n_2, 6);

        note->nota.n_3 = set_coordinate(note->nota.n_3, 8);
        note->nenota.n_3 = set_coordinate(note->nenota.n_3, 8);
    }
}
