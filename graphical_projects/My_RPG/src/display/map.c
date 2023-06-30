/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** map
*/
#include "../../include/my.h"

void map_display(struct_t *data)
{
    sfRenderWindow_clear(WIN, sfBlack);
    sfRenderWindow_setView(WIN, data->view);
    sfRenderWindow_drawSprite(WIN, data->bg.sprite, NULL);
    sfRenderWindow_drawSprite(WIN, data->icon[0], NULL);
    sfRenderWindow_display(WIN);
}
