/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** main file
*/
#include "../include/radar.h"

void analyse_evt(sfEvent evt, global_t *data)
{
    if (evt.type == sfEvtClosed)
        sfRenderWindow_close(data->window);
    if (evt.type == sfEvtKeyReleased && evt.key.code == sfKeyL) {
        if (data->view_hitbox == 1) {
            data->view_hitbox = 0;
        } else {
            data->view_hitbox = 1;
        }
    }
    if (evt.type == sfEvtKeyReleased && evt.key.code == sfKeyS) {
        if (data->sprite_view == 1) {
            data->sprite_view = 0;
        } else {
            data->sprite_view = 1;
        }
    }
    return;
}

void display_radar(global_t *data, tower_t *tower, plane_t *plane)
{
    while (tower != NULL) {
        if (data->view_hitbox == 1)
            create_circle(tower, data);
        if (data->sprite_view == 1)
            sfRenderWindow_drawSprite(data->window, tower->sprite, NULL);
        tower = tower->T2;
    }
    while (plane != NULL) {
        if (data->view_hitbox == 1 && plane->done == 0 &&
            data->take_off_timer >= plane->str_flight)
            create_hitbox(plane, data);
        if (data->sprite_view == 1 && plane->done == 0 &&
            data->take_off_timer >= plane->str_flight)
            sfRenderWindow_drawSprite(data->window, plane->sprite, NULL);
        plane = plane->P2;
    }
    return;
}

void init_data_radar(global_t *data)
{
    data->window;
    data->clock = sfClock_create();
    data->timer = sfClock_create();
    data->map = sfSprite_create();
    data->map_txt = sfTexture_createFromFile("./images/map.png", NULL);
    data->done = sfSprite_create();
    data->done_txt = sfTexture_createFromFile("./images/done.jpg", NULL);

    data->take_off_timer = 0;
    data->end_value = 0;
    sfSprite_setTexture(data->map, data->map_txt, sfFalse);
    sfSprite_setTexture(data->done, data->done_txt, sfFalse);
    return;
}

void play_radar(global_t *data, tower_t *tower, plane_t *plane)
{
    init_data_radar(data);
    sfVideoMode mode = {1920, 1080, 32};
    sfEvent event;

    data->window = sfRenderWindow_create(mode, "R", sfResize | sfClose, NULL);
    while (sfRenderWindow_isOpen(data->window)) {
        sfRenderWindow_display(data->window);
        sfRenderWindow_clear(data->window, sfBlack);
        sfRenderWindow_drawSprite(data->window, data->map, NULL);
        make_clock(data, plane, tower);
        display_radar(data, tower, plane);
        collision(data, plane, tower);
        if (data->end_value == data->planes)
            sfRenderWindow_drawSprite(data->window, data->done, NULL);
        while (sfRenderWindow_pollEvent(data->window, &event))
            analyse_evt(event, data);
    }
    destroy(data, tower, plane);
    return;
}
