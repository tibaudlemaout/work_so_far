/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** in_game_menu
*/
#include "../../include/my.h"

void in_game_menu_is_button_hover(menu_t *menu, sfVector2i posi)
{
    sfColor on = sfColor_fromRGB(100, 100, 100);
    sfColor off = sfColor_fromRGB(160, 160, 160);
    sfVector2f pos;

    for (int i = 0; i < 4; i++) {
        pos = sfRectangleShape_getPosition(menu->icon[i].button.rect);
        if (posi.x >= pos.x && posi.x <= pos.x + 180 &&
            posi.y >= pos.y && posi.y <= pos.y + 180)
            sfRectangleShape_setFillColor(menu->icon[i].button.rect, on);
        else
            sfRectangleShape_setFillColor(menu->icon[i].button.rect, off);
    }
}

void in_game_menu_is_button_clicked(struct_t *data, menu_t *menu, sfVector2i p)
{
    sfVector2f pos;
    int i = 0;
    int check = 0;

    for (i = 0; i < 4; i++) {
        pos = sfRectangleShape_getPosition(menu->icon[i].button.rect);
        if (p.x >= pos.x && p.x <= pos.x + 180 &&
            p.y >= pos.y && p.y <= pos.y + 180) {
            check = 1;
            break;
        }
    }
    if (check == 1 && i == 0)
        data->set = 9;
    if (check == 1 && i == 1)
        data->set = 10;
    if (check == 1 && i == 2)
        data->set = 15;
    if (check == 1 && i == 3)
        data->set = 15;
}

void in_game_menu_manage_events(struct_t *data, menu_t *menu)
{
    sfVector2i posi = get_mouse_position(data);

    if (EVENT.type == sfEvtClosed)
        data->set = 0;
    in_game_menu_is_button_hover(menu, posi);
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code == sfKeyEscape)
        data->set = data->old_set;
    if (EVENT.type == sfEvtMouseButtonReleased &&
        EVENT.key.code == sfMouseLeft) {
        if (posi.x >= 30 && posi.x <= 130 && posi.y >= 30 && posi.y <= 130)
            data->set = data->old_set;
        if (posi.x >= 1805 && posi.x <= 1920 && posi.y >= 30 && posi.y <= 130)
            data->set = 15;
        in_game_menu_is_button_clicked(data, menu, posi);
    }
}
