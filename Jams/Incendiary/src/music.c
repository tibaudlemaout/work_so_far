/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** music
*/
#include "../include/struct.h"
#include "../include/my.h"
#include "../include/define.h"

void init_sound(struct_t *all)
{
    all->soundtrack = malloc(sizeof(audio_t) * 3);
    all->soundtrack[0].music = sfMusic_createFromFile("asset/sounds/Extinguished.ogg");
    all->soundtrack[1].music = sfMusic_createFromFile("asset/sounds/Fire_Fight.ogg");
    all->soundtrack[2].music = sfMusic_createFromFile("asset/sounds/Fire_Crackling.ogg");

    sfMusic_setVolume(all->soundtrack[0].music, 40);
    sfMusic_setLoop(all->soundtrack[0].music, sfTrue);
    sfMusic_play(all->soundtrack[0].music);
    sfMusic_setVolume(all->soundtrack[1].music, 25);
    sfMusic_setLoop(all->soundtrack[1].music, sfTrue);
    sfMusic_stop(all->soundtrack[1].music);
    sfMusic_setVolume(all->soundtrack[2].music, 70);
    sfMusic_setLoop(all->soundtrack[2].music, sfTrue);
    sfMusic_stop(all->soundtrack[2].music);
    return;
}

void ingame_audio(struct_t *all)
{
    sfMusic_stop(all->soundtrack[0].music);
    sfMusic_play(all->soundtrack[1].music);
    sfMusic_play(all->soundtrack[2].music);
    return;
}

void win_audio(struct_t *all)
{
    sfMusic_stop(all->soundtrack[1].music);
    sfMusic_stop(all->soundtrack[2].music);
    sfMusic_play(all->soundtrack[0].music);
    return;
}
