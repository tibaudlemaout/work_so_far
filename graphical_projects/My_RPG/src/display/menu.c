/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** menu
*/
#include "../../include/my.h"

void menu_display(struct_t *data, menu_t *menu)
{
    sfRenderWindow_clear(WIN, sfBlack);
    sfRenderWindow_setView(WIN, data->view);
    sfRenderWindow_drawSprite(WIN, menu->bg_day.sprite, NULL);
    sfRenderWindow_drawSprite(WIN, menu->sign1.sprite, NULL);
    sfRenderWindow_drawSprite(WIN, menu->sign2.sprite, NULL);
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawText(WIN, menu->text[i].txt, NULL);
    sfRenderWindow_display(WIN);
}
