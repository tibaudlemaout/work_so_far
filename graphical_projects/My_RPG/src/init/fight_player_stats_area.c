/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** fight_stats_area
*/
#include "../../include/my.h"

void init_player_attdefspd_area(fight_t *fight)
{
    ADSarea.rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(ADSarea.rect, sfTransparent);
    sfRectangleShape_setOutlineColor(ADSarea.rect, sfWhite);
    sfRectangleShape_setOutlineThickness(ADSarea.rect, 5);
    sfRectangleShape_setSize(ADSarea.rect, (sfVector2f) {200, 190});
    sfRectangleShape_setPosition(ADSarea.rect, (sfVector2f) {1650, 820});
}

void init_player_stats_area(struct_t *data, fight_t *fight)
{
    sfColor grey = sfColor_fromRGB(160, 160, 160);
    sfVector2f pos = {1350, 805};

    fight->player_area.rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(fight->player_area.rect, grey);
    sfRectangleShape_setOutlineColor(fight->player_area.rect, sfWhite);
    sfRectangleShape_setOutlineThickness(fight->player_area.rect, 3);
    sfRectangleShape_setSize(fight->player_area.rect, (sfVector2f) {515, 220});
    sfRectangleShape_setPosition(fight->player_area.rect, pos);
    fight->player_area.display = 1;
    init_player_attdefspd_area(fight);
}
