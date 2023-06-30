/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** manage_clock
*/
#include "../include/radar.h"

void make_clock(global_t *data, plane_t *plane, tower_t *tower)
{
    data->plane_timer = sfClock_getElapsedTime(data->timer);
    data->time = sfClock_getElapsedTime(data->clock);
    data->seconds = data->time.microseconds / 1000000.0;
    data->disp_timer = data->plane_timer.microseconds / 1000000.0;
    if (data->disp_timer > 1.0) {
        data->take_off_timer ++;
        sfClock_restart(data->timer);
    }
    if (data->seconds > 0.1) {
        move_hitbox(plane, data);
        sfClock_restart(data->clock);
    }
}
