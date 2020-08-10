#include "header.h"

int scoreboard(SDL_Renderer *renderer) {
    bool running = true;
    SDL_Event event;
    if (TTF_Init() == -1) {
        printf("TTF_Init:%s\n", TTF_GetError());
        exit(2);
    }
    int page = 0;
    TTF_Font *font = TTF_OpenFont(path_for_res("ARIAL.TTF"), 25);

    SDL_Color color = {255, 255, 0, 255};
    SDL_Color colorGR = {155, 255, 0, 255};


    SDL_Rect backgroundRect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
    SDL_Texture *imageBackground =
            IMG_LoadTexture(renderer, path_for_res("empty_back.png"));

    while (running) {
        int file = open(path_for_res("scoreboard.txt"),
                        O_RDWR | O_APPEND, S_IRUSR | S_IWUSR | S_IXUSR);
        int status = 1;
        int i = 0;
        int y = 6;
        int z = 0;
        int topage = 6;
        SDL_RenderCopy(renderer, imageBackground, NULL, &backgroundRect);
        draw_text(colorGR, 400, 50, "Scoreboard", renderer, font);
        draw_text(colorGR, 50, 100, "Name", renderer, font);
        draw_text(color, 250, 100, "Games", renderer, font);
        // draw_text(colorGR, 350, 300, "Name", renderer, font);
        draw_text(color, 500, 100, "Wins", renderer, font);
        while (status) {
            i = 0;

            char *name = mx_strnew(100);
            char *games = mx_strnew(100);
            char *win = mx_strnew(100);
            while ((status = read(file, &z, 1)) && z != ' ') {
                name[i] = z;
                i++;
            }
            name[i] = 0;
            i = 0;
            while (read(file, &z, 1) && z != ' ') {
                games[i] = z;
                i++;
            }
            i = 0;
            while (read(file, &z, 1) && z != '\n') {
                win[i] = z;
                i++;
            }
            if (((y - 6) >= page * 14) && ((y - 6) < (page + 1) * 14)) {
                draw_text(colorGR, 50, 25 * topage, name, renderer, font);
                draw_text(colorGR, 250, 25 * topage, games, renderer, font);
                draw_text(colorGR, 500, 25 * topage, win, renderer, font);
                topage++;
            }
            free(name);
            free(games);
            free(win);
            y++;
        }
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYUP) {
                if (event.key.keysym.sym == SDLK_RIGHT) {
                    page++;
                    printf("%d", page);
                }
                if (event.key.keysym.sym == SDLK_LEFT) {
                    if (page > 0) page--;
                }
                if (event.key.keysym.sym == SDLK_ESCAPE 
                    || event.key.keysym.sym == SDLK_SPACE 
                    || event.key.keysym.sym == SDLK_q
                    || event.key.keysym.sym == SDLK_RETURN) {
                    TTF_CloseFont(font);
                    return 6;
                }
            }
        }
        usleep(10000);
        SDL_RenderPresent(renderer);
        close(file);
    }
    SDL_DestroyTexture(imageBackground);
    return 1;
}
