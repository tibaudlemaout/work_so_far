/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** name
*/
#include "../../include/my.h"

void manage_name_input(struct_t *data, menu_t *menu)
{
    if (EVENT.text.unicode == 8 && menu->idx >= 0) {
        P.name[menu->idx] = '\0';
        if (menu->idx != 0)
            menu->idx--;
        sfText_setString(menu->name.txt, P.name);
        return;
    }
    if (EVENT.text.unicode < 128 && EVENT.text.unicode != 8) {
        if (my_strlen(P.name) < 16) {
            P.name[menu->idx] = EVENT.text.unicode;
            menu->idx++;
            P.name[menu->idx] = '\0';
            sfText_setString(menu->name.txt, P.name);
        }
    }
}

void is_play_text_clicked(struct_t *data, menu_t *menu, sfVector2i posi)
{
    sfVector2f pos = sfSprite_getPosition(menu->sign3.sprite);
    if (posi.x >= pos.x && posi.x <= pos.x + 240 &&
        posi.y >= pos.y - 50 && posi.y <= pos.y + 40) {
        if (menu->idx > 0)
            data->set = 5;
    }
}

void is_play_text_hover(menu_t *menu, sfVector2i posi)
{
    sfVector2f pos = sfSprite_getPosition(menu->sign3.sprite);
    if (posi.x >= pos.x && posi.x <= pos.x + 240 &&
        posi.y >= pos.y - 50 && posi.y <= pos.y + 40)
        sfText_setColor(menu->text[5].txt, sfWhite);
    else
        sfText_setColor(menu->text[5].txt, sfBlack);
}

void name_manage_events(struct_t *data, menu_t *menu)
{
    sfVector2i posi = get_mouse_position(data);
    if (EVENT.type == sfEvtClosed)
        data->set = 0;
    if (EVENT.type == sfEvtMouseButtonReleased && EVENT.key.code == sfMouseLeft)
        is_play_text_clicked(data, menu, posi);
    is_play_text_hover(menu, posi);
    if (EVENT.type == sfEvtTextEntered)
        manage_name_input(data, menu);
    if (menu->idx == 0)
        sfText_setColor(menu->text[5].txt, sfColor_fromRGB(120, 120, 120));
}
