/*
** EPITECH PROJECT, 2023
** C_Graphical
** File description:
** create_objects
*/
#include "../include/radar.h"

void create_tower(global_t *data, tower_t **tower)
{
    tower_t *tower_list = malloc(sizeof(tower_t));
    sfVector2f t_scl = {0.20, 0.20};

    tower_list->rds = (1920 / 100) * data->t_rds;
    tower_list->t_pos.x = data->tx_pos - 50;
    tower_list->t_pos.y = data->ty_pos - 50;

    tower_list->sprite = sfSprite_create();
    tower_list->texture = sfTexture_createFromFile("./images/twr.png", NULL);
    sfSprite_setTexture(tower_list->sprite, tower_list->texture, sfFalse);
    sfSprite_setPosition(tower_list->sprite, tower_list->t_pos);
    sfSprite_setScale(tower_list->sprite, t_scl);
    tower_list->T2 = *tower;
    *tower = tower_list;
    return;
}

void plane_settings(global_t *data, plane_t *plane_list)
{
    plane_list->sprite = sfSprite_create();
    plane_list->texture = sfTexture_createFromFile("./images/pln.png", NULL);

    set_movement(plane_list);
    sfSprite_setTexture(plane_list->sprite, plane_list->texture, sfFalse);
    sfSprite_setPosition(plane_list->sprite, plane_list->a_pos);
    return;
}

void create_plane(global_t *data, plane_t **plane)
{
    plane_t *plane_list = malloc(sizeof(plane_t));
    sfVector2f p_scl = {0.10, 0.10};
    sfVector2f origin = {100, 100};

    plane_list->done = 0;
    plane_list->invuln = 0;
    plane_list->a_pos.y = data->py_str;
    plane_list->a_pos.x = data->px_str;
    plane_list->end_pos.y = data->py_end;
    plane_list->end_pos.x = data->px_end;
    plane_list->speed = data->p_spd;
    plane_list->str_flight = data->p_take_off;

    plane_settings(data, plane_list);
    sfSprite_setOrigin(plane_list->sprite, origin);
    sfSprite_setScale(plane_list->sprite, p_scl);
    plane_list->P2 = *plane;
    *plane = plane_list;
    return;
}

void create_circle(tower_t *t, global_t *data)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfVector2f pos = {t->t_pos.x - t->rds + 50, t->t_pos.y - t->rds + 50};

    sfCircleShape_setPosition(circle, pos);
    sfCircleShape_setRadius(circle, t->rds);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineColor(circle, sfRed);
    sfCircleShape_setOutlineThickness(circle, 1);
    sfRenderWindow_drawCircleShape(data->window, circle, NULL);
    sfCircleShape_destroy(circle);
}

void create_hitbox(plane_t *plane, global_t *data)
{
    sfRectangleShape *hitbox = sfRectangleShape_create();
    sfVector2f pos = {plane->a_pos.x, plane->a_pos.y};
    sfVector2f size = {20, 20};
    sfVector2f origin = {10, 10};

    sfRectangleShape_setPosition(hitbox, pos);
    sfRectangleShape_setOrigin(hitbox, origin);
    sfRectangleShape_setFillColor(hitbox, sfTransparent);
    if (plane->invuln == 0)
        sfRectangleShape_setOutlineColor(hitbox, sfRed);
    if (plane->invuln == 1)
        sfRectangleShape_setOutlineColor(hitbox, sfGreen);
    sfRectangleShape_setOutlineThickness(hitbox, 1);
    sfRectangleShape_setSize(hitbox, size);
    sfRenderWindow_drawRectangleShape(data->window, hitbox, NULL);
    sfRectangleShape_destroy(hitbox);
}
