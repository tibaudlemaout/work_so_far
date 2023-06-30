/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** handle_plane
*/
#include "../include/radar.h"

void set_movement(plane_t *plane)
{
    float hypothenuse;

    plane->mvmt.x = plane->end_pos.x - plane->a_pos.x;
    plane->mvmt.y = plane->end_pos.y - plane->a_pos.y;
    hypothenuse = sqrt((pow(plane->mvmt.x, 2) + pow(plane->mvmt.y, 2)));
    plane->mvmt.x = plane->mvmt.x / hypothenuse;
    plane->mvmt.y = plane->mvmt.y / hypothenuse;
}

void final_adjust(global_t *data, plane_t *plane, float dist_x, float dist_y)
{
    plane->a_pos.x += (plane->mvmt.x * (plane->speed / 10) - dist_x);
    plane->a_pos.y += (plane->mvmt.y * (plane->speed / 10) - dist_y);
    plane->done = 1;
    data->end_value += 1;
    return;
}

void dist_calc(plane_t *plane, global_t *data, float dist_x, float dist_y)
{
    dist_x = plane->end_pos.x - plane->a_pos.x;
    dist_y = plane->end_pos.y - plane->a_pos.y;

    if (dist_x < 0)
        dist_x = plane->a_pos.x - plane->end_pos.x;
    if (dist_y < 0)
        dist_y = plane->a_pos.y - plane->end_pos.y;
    if (dist_x > (plane->speed / 10) || dist_y > (plane->speed / 10)) {
        plane->a_pos.x += (plane->mvmt.x * (plane->speed / 10));
        plane->a_pos.y += (plane->mvmt.y * (plane->speed / 10));
    } else if (plane->done == 0)
        final_adjust(data, plane, dist_x, dist_y);
    sfSprite_setPosition(plane->sprite, plane->a_pos);
    return;
}

void move_hitbox(plane_t *plane, global_t *data)
{
    float dist_x;
    float dist_y;

    while (plane != NULL) {
        dist_calc(plane, data, dist_x, dist_y);
        plane = plane->P2;
    }
    return;
}
