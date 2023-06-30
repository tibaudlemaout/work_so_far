/*
** EPITECH PROJECT, 2023
** Semester_2
** File description:
** music
*/
#include "../../include/my.h"

void init_music(struct_t *data)
{
    data->music = malloc(sizeof(audio_t) * 3);
    data->music[0].st = sfMusic_createFromFile("../../asset/music/menu.ogg");
    data->music[1].st = sfMusic_createFromFile("../../asset/music/ambiant.ogg");
    data->music[2].st = sfMusic_createFromFile("../../asset/music/battle.ogg");

    sfMusic_setVolume(data->music[0].st, 40);
    sfMusic_setLoop(data->music[0].st, sfTrue);
    sfMusic_setVolume(data->music[1].st, 40);
    sfMusic_setLoop(data->music[1].st, sfTrue);
    sfMusic_stop(data->music[1].st);
    sfMusic_setVolume(data->music[2].st, 20);
    sfMusic_setLoop(data->music[2].st, sfTrue);
    sfMusic_stop(data->music[2].st);
    return;
}

