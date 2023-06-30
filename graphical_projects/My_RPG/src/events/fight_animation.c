/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** fight_animation
*/
#include "../../include/my.h"

void fight_animation_manage_events(struct_t *data)
{
    if (EVENT.type == sfEvtClosed)
        data->set = 0;
}
