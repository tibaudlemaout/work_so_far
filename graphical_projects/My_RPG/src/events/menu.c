/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** menu
*/
#include "../../include/my.h"

void is_text_hover(menu_t *menu, sfVector2i posi)
{
    if (posi.x >= 1092 && posi.x <= 1290 && posi.y >= 485 && posi.y <= 540) {
        sfText_setColor(menu->text[0].txt, sfWhite);
    } else
        sfText_setColor(menu->text[0].txt, sfBlack);
    if (posi.x >= 1092 && posi.x <= 1290 && posi.y >= 565 && posi.y <= 625) {
        sfText_setColor(menu->text[1].txt, sfWhite);
    } else
        sfText_setColor(menu->text[1].txt, sfBlack);
    if (posi.x >= 1092 && posi.x <= 1290 && posi.y >= 645 && posi.y <= 705) {
        sfText_setColor(menu->text[2].txt, sfWhite);
    } else
        sfText_setColor(menu->text[2].txt, sfBlack);
    if (posi.x >= 310 && posi.x <= 460 && posi.y >= 830 && posi.y <= 930) {
        sfText_setColor(menu->text[3].txt, sfWhite);
    } else
        sfText_setColor(menu->text[3].txt, sfBlack);
}

void is_text_clicked(struct_t *data, menu_t *menu, sfVector2i posi)
{
    if (posi.x >= 1092 && posi.x <= 1290 && posi.y >= 485 && posi.y <= 540)
        data->set = 3;
    if (posi.x >= 1092 && posi.x <= 1290 && posi.y >= 565 && posi.y <= 625)
        load_save(data);
    if (posi.x >= 1092 && posi.x <= 1290 && posi.y >= 645 && posi.y <= 705)
        printf("settings\n"); fflush(stdout);
    if (posi.x >= 310 && posi.x <= 460 && posi.y >= 830 && posi.y <= 930)
        data->set = 0;
}

void menu_manage_events(struct_t *data, menu_t *menu)
{
    sfVector2i posi = get_mouse_position(data);
    if (EVENT.type == sfEvtClosed)
        data->set = 0;
    if (EVENT.type == sfEvtMouseButtonReleased && EVENT.key.code == sfMouseLeft)
        is_text_clicked(data, menu, posi);
    is_text_hover(menu, posi);
}
