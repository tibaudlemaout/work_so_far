/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** selection
*/
#include "../../include/my.h"

void selection_display(struct_t *data, menu_t *menu)
{
    sfRenderWindow_clear(WIN, sfBlack);
    sfRenderWindow_setView(WIN, data->view);
    sfRenderWindow_drawSprite(WIN, menu->bg_selection.sprite, NULL);
    for (int i = 0; i < 8; i++)
        sfRenderWindow_drawSprite(WIN, FRAME[i].sprite, NULL);
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawSprite(WIN, AVATAR[i].sprite, NULL);
        sfRenderWindow_drawText(WIN, menu->stats[i].txt, NULL);
        sfRenderWindow_drawRectangleShape(WIN, menu->rect[i], NULL);
    }
    sfRenderWindow_drawSprite(WIN, menu->sign3.sprite, NULL);
    sfRenderWindow_drawText(WIN, menu->text[4].txt, NULL);
    sfRenderWindow_display(WIN);
}
