/*
** EPITECH PROJECT, 2023
** Paint
** File description:
** buttons
*/
#include "../../include/my.h"

void init_pencils_drop_down(menu_t *menu)
{
    sfVector2f position = {770, 565};
    sfVector2f size = {100, 30};
    for (int i = 3; i < 5; i++) {
        menu->button[i].rect = sfRectangleShape_create();
        sfRectangleShape_setFillColor(menu->button[i].rect, sfWhite);
        // sfRectangleShape_setOutlineColor(menu->button[i].rect, sfColor_fromRGB(160, 160, 160));
        // sfRectangleShape_setOutlineThickness(menu->button[i].rect, 3);
        sfRectangleShape_setSize(menu->button[i].rect, size);
        menu->button[i].pos.x = position.x;
        menu->button[i].pos.y = position.y;
        sfRectangleShape_setPosition(menu->button[i].rect, position);
        menu->button[i].display = 0;
        menu->button[i].clicked = 0;
        position.y += (size.y + 5);
    }
}

void init_menu_buttons(menu_t *menu)
{
    menu->button = malloc(sizeof(button_t) * 5);
    sfVector2f position = {770, 478};
    sfVector2f size = {80, 80};
    for (int i = 0; i < 3; i++) {
        if (i == 2) {
            size.x += 10;
            position.x -= 5;
        }
        menu->button[i].rect = sfRectangleShape_create();
        sfRectangleShape_setFillColor(menu->button[i].rect, sfTransparent);
        sfRectangleShape_setOutlineColor(menu->button[i].rect, sfColor_fromRGB(160, 160, 160));
        sfRectangleShape_setOutlineThickness(menu->button[i].rect, 3);
        sfRectangleShape_setSize(menu->button[i].rect, size);
        menu->button[i].pos.x = position.x;
        menu->button[i].pos.y = position.y;
        sfRectangleShape_setPosition(menu->button[i].rect, position);
        menu->button[i].display = 1;
        position.x += 115;
    }
    init_pencils_drop_down(menu);
}
