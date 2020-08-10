//
// Created by Rostyslav Druzhchenko on 04.05.2020.
//

#include <application.h>
#include <stdlib.h>

App *get_application() {
    static App *application = 0;
    if (application == 0) {
        application = (App *) malloc(sizeof(App));
    }
    return application;
}

void destroy_application() {
    App *application = get_application();
    SDL_DestroyRenderer(application->renderer);
    SDL_DestroyWindow(application->window);
    free(application);
}
