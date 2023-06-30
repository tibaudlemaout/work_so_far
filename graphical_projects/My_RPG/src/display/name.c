/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** name
*/
#include "../../include/my.h"

void name_display(struct_t *data, menu_t *menu)
{
    sfRenderWindow_clear(WIN, sfBlack);
    sfRenderWindow_setView(WIN, data->view);
    sfRenderWindow_drawSprite(WIN, menu->bg_selection.sprite, NULL);
    sfRenderWindow_drawSprite(WIN, menu->sign3.sprite, NULL);
    sfRenderWindow_drawSprite(WIN, menu->input.sprite, NULL);
    sfRenderWindow_drawText(WIN, menu->name_txt.txt, NULL);
    sfRenderWindow_drawText(WIN, menu->text[5].txt, NULL);
    sfRenderWindow_drawText(WIN, menu->name.txt, NULL);
    sfRenderWindow_display(WIN);
}
