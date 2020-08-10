#include <application.h>
#include "header.h"

int main() {
    srand(time(0));

    App *app = get_application();
    init_sdl(app);

    present_logo_scene();
    menu_callback(app);

    TTF_Quit();
    SDL_Quit();
    destroy_application();

    return 0;
}

void menu_callback(App *app) {
    int scene = 6;
    while (scene == 3 || scene == 6 || scene == 5) {
        scene = show_menu(app->renderer);
        if (scene == 3) {
            scene = scoreboard(app->renderer);
        }
        if (scene == 5)
            scene = show_about(app->renderer);
        if (scene == 2)
            scene = show_players(app->renderer);
    }
    if (scene == 1) {
        t_entity *player = malloc(sizeof(t_entity));
        t_notes *note = (t_notes *) malloc(sizeof(t_notes));
        create_notes(app, note);
        note->nota.n_1.x = init_random(0, 700);
        note->nenota.n_1.x = init_random(0, 700);

        note->nota.n_2.x = init_random(0, 700);
        note->nenota.n_2.x = init_random(0, 700);

        note->nota.n_3.x = init_random(0, 700);
        note->nenota.n_3.x = init_random(0, 700);

        note->step = 1;
        present_game_scene(app, player, note);
    }
}
