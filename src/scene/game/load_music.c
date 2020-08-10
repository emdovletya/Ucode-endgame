//
// Created by User on 04.05.2020.
//
#include "header.h"

void load_music(t_entity *player) {
    //Initialize SDL mixer
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    //Load audio files
    int n = 9;
    char *tracks[] = {
            "mp3/bgsa.mp3",
            "mp3/hl.mp3",
            "mp3/exp.mp3",
            "mp3/cck.mp3",
            "mp3/inah.mp3",
            "mp3/doowit.mp3",
            "mp3/jj.mp3",
            "mp3/h2h.mp3",
            "mp3/never-gonna-give-you-up.mp3"};
    int i = rand() % n;
    const char *path = path_for_res(tracks[i]);

    player->level_song = Mix_LoadMUS(path);
}
