#ifndef HEADER_H
#define HEADER_H

#define WINDOW_WIDTH (800)
#define WINDOW_HEIGHT (600)
#define SCROLL_SPEED (1000)

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <sdl_all.h>
#include <application.h>

typedef struct s_entity {
    SDL_Rect *rect;
    SDL_Texture *background;
    Mix_Music *level_song;
}              t_entity;

typedef struct s_hearts {
    SDL_Texture *full;
    SDL_Texture *half;
    SDL_Texture *empty;
    SDL_Rect heart_pos1;
    SDL_Rect heart_pos2;
    SDL_Rect heart_pos3;
}              t_hearts;


typedef struct s_img {
    SDL_Surface *srf;
    SDL_Texture *texture;
    SDL_Rect n_1;
    SDL_Rect n_2;
    SDL_Rect n_3;
}              t_img;

typedef struct s_notes {
    // SDL_Surface *txt;  // для подсчета чисел
    // // SDL_Surface *game_over;  // для game over

    // int hp;
    // int score;
    int step;

    t_img nota;
    t_img nenota;
}              t_notes;

int init_random(int low, int high);

typedef struct s_score {
    SDL_Texture *texture1;
    SDL_Texture *texture2;
    SDL_Color color;
    TTF_Font *font;
    SDL_Rect score_rect;
    SDL_Rect current_score_rect;
}              t_score;

typedef struct s_sprite {
    SDL_Texture *texture;
    SDL_Rect rect;
}              t_sprite;

#define MX_RES(a) path_for_res(a)

void init_sdl(App *app);
void load_music(t_entity *player);
void cleanup(App *app);
const char *path_for_res(const char *file_name);
void menu_callback(App *app);
void
draw_text(SDL_Color color, int x, int y, char *text, SDL_Renderer *renderer,
          TTF_Font *font);

#include <hero.h>

// Scenes
int scoreboard(SDL_Renderer *renderer);
bool compare(SDL_Rect a, SDL_Rect b);
void present_game_scene(App *app, t_entity *player, t_notes *note);
int show_menu(SDL_Renderer *renderer);
void present_logo_scene();
void add_hero_lives_textures(SDL_Renderer *renderer, t_hearts *hearts);
void render_hearts(SDL_Renderer *renderer, t_hearts *hearts, int lives);
void print_notes(App *app, t_notes *note, int lives);
void create_notes(App *app, t_notes *note);
SDL_Rect set_coordinate(SDL_Rect rct, int speed);
void note_falling(t_notes *note);
void show_score(SDL_Renderer *renderer, t_score *score);
int show_about(SDL_Renderer *renderer);
int show_players(SDL_Renderer *renderer);

//Count parameters of hero
int hero_hp(t_notes *note, t_hero hero, int lives);
int hero_score(t_notes *note, t_hero hero, int current_score);


//Other
char *mx_strnew(const int size);

#endif
