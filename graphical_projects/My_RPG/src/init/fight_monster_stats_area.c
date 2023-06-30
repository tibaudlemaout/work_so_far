/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** fight_stats_area
*/
#include "../../include/my.h"

void init_monster_stats_area(struct_t *data, fight_t *fight)
{
    sfColor grey = sfColor_fromRGB(160, 160, 160);
    sfVector2f size = {515, 220};
    sfVector2f pos = {120, 120};

    fight->monster_area.rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(fight->monster_area.rect, grey);
    sfRectangleShape_setOutlineColor(fight->monster_area.rect, sfWhite);
    sfRectangleShape_setOutlineThickness(fight->monster_area.rect, 3);
    sfRectangleShape_setSize(fight->monster_area.rect, size);
    sfRectangleShape_setPosition(fight->monster_area.rect, pos);
    fight->monster_area.display = 1;
    fight->monster_area.hover = 0;
}
