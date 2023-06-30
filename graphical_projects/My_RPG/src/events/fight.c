/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** fight
*/
#include "../../include/my.h"

void is_button_hover(fight_t *fight, sfVector2i posi)
{
    sfColor on = sfColor_fromRGB(100, 100, 100);
    sfColor off = sfColor_fromRGB(160, 160, 160);

    if (posi.x >= 50 && posi.x <= 650 && posi.y >= 767 && posi.y <= 863) {
        sfRectangleShape_setFillColor(fight->button[0].rect, on);
    } else
        sfRectangleShape_setFillColor(fight->button[0].rect, off);
    if (posi.x >= 670 && posi.x <= 1270 && posi.y >= 767 && posi.y <= 863) {
        sfRectangleShape_setFillColor(fight->button[1].rect, on);
    } else
        sfRectangleShape_setFillColor(fight->button[1].rect, off);
    if (posi.x >= 50 && posi.x <= 650 && posi.y >= 882 && posi.y <= 978) {
        sfRectangleShape_setFillColor(fight->button[2].rect, on);
    } else
        sfRectangleShape_setFillColor(fight->button[2].rect, off);
    if (posi.x >= 670 && posi.x <= 1270 && posi.y >= 882 && posi.y <= 978) {
        sfRectangleShape_setFillColor(fight->button[3].rect, on);
    } else
        sfRectangleShape_setFillColor(fight->button[3].rect, off);
}

void is_button_clicked(struct_t *data, fight_t *fight, sfVector2i posi)
{
    M.old_hp = M.hp;
    if (posi.x >= 50 && posi.x <= 650 && posi.y >= 767 && posi.y <= 863) {
        M.hp -= (P.stat.att - ((M.ads[1] / 100) * P.stat.att));
        fight->player_turn = 0;
    }
    if (posi.x >= 670 && posi.x <= 1270 && posi.y >= 767 && posi.y <= 863) {
        M.ads[0] -= 3;
        fight->player_turn = 0;
    }
    if (posi.x >= 50 && posi.x <= 650 && posi.y >= 882 && posi.y <= 978) {
        M.ads[1] -= ((20 * P.stat.att) / 100);
        fight->player_turn = 0;
    }
    if (posi.x >= 670 && posi.x <= 1270 && posi.y >= 882 && posi.y <= 978) {
        M.ads[2] -= ((50 * P.stat.att) / 100);
        fight->player_turn = 0;
    }
    monster_damages_animation(data, fight, M.old_hp - M.hp, 1);
}

void fight_manage_events(struct_t *data, fight_t *fight)
{
    sfVector2i posi = get_mouse_position(data);
    if (EVENT.type == sfEvtClosed)
        data->set = 0;
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code == sfKeySpace)
        data->set = data->old_set;
    is_button_hover(fight, posi);
    if (P.stat.hp <= 0)
        data->set = data->old_set;
    if (fight->player_turn == 1) {
        if (EVENT.type == sfEvtMouseButtonReleased &&
            EVENT.key.code == sfMouseLeft)
            is_button_clicked(data, fight, posi);
    }
    if (M.hp <= 0)
        data->set = 8;
}
