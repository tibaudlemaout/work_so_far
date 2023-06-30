/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** functions to destray all previous create
*/
#include "../include/radar.h"

void destroy(global_t *data, tower_t *tower, plane_t *plane)
{
    sfRenderWindow_destroy(data->window);
    sfClock_destroy(data->clock);
    sfClock_destroy(data->timer);
    sfSprite_destroy(data->map);
    sfTexture_destroy(data->map_txt);
    sfSprite_destroy(data->done);
    sfTexture_destroy(data->done_txt);
    while (tower != NULL) {
        sfSprite_destroy(tower->sprite);
        sfTexture_destroy(tower->texture);
        tower = tower->T2;
    }
    while (plane != NULL) {
        sfSprite_destroy(plane->sprite);
        sfTexture_destroy(plane->texture);
        plane = plane->P2;
    }
    return;
}
