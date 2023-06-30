/*
** EPITECH PROJECT, 2023
** Paint
** File description:
** colors
*/
#include "../../include/my.h"

void init_colors_on(menu_t *menu)
{
    menu->b_color_on = malloc(sizeof(button_t) * 7);
    sfVector2f position = {200, 85};
    sfVector2f size = {30, 30};
    for (int i = 0; i < 7; i++) {
        menu->b_color_on[i].rect = sfRectangleShape_create();
        sfRectangleShape_setFillColor(menu->b_color_on[i].rect, sfColor_fromRGBA(0, 0, 0, 100));
        sfRectangleShape_setOutlineColor(menu->b_color_on[i].rect, menu->color[i]);
        sfRectangleShape_setOutlineThickness(menu->b_color_on[i].rect, 2);
        sfRectangleShape_setSize(menu->b_color_on[i].rect, size);
        menu->b_color_on[i].pos.x = position.x;
        menu->b_color_on[i].pos.y = position.y;
        sfRectangleShape_setPosition(menu->b_color_on[i].rect, position);
        position.x += 40;
    }
    return;
}

void init_colors(menu_t *menu)
{
    menu->b_color = malloc(sizeof(button_t) * 7);
    sfVector2f position = {200, 85};
    sfVector2f size = {30, 30};
    for (int i = 0; i < 7; i++) {
        menu->b_color[i].rect = sfRectangleShape_create();
        sfRectangleShape_setFillColor(menu->b_color[i].rect, menu->color[i]);
        sfRectangleShape_setOutlineColor(menu->b_color[i].rect, sfColor_fromRGB(160, 160, 160));
        sfRectangleShape_setOutlineThickness(menu->b_color[i].rect, 2);
        sfRectangleShape_setSize(menu->b_color[i].rect, size);
        menu->b_color[i].pos.x = position.x;
        menu->b_color[i].pos.y = position.y;
        sfRectangleShape_setPosition(menu->b_color[i].rect, position);
        menu->b_color[i].display = 1;
        position.x += 40;
    }
    init_colors_on(menu);
    return;
}
