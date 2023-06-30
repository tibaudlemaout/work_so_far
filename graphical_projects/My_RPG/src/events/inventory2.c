/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** inventory2
*/
#include "../../include/my.h"

void update_player_stats(struct_t *data, int idx)
{
    P.stat.hpMax = P.stat.Default_hpMax;
    P.stat.att = P.stat.Default_att;
    P.stat.def = P.stat.Default_def;
    P.stat.spd = P.stat.Default_spd;
    for (int i = 0; i < 5; i++) {
        if (data->inventory.tab[i].taken == 1) {
            P.stat.hpMax += data->inventory.tab[i].item.hp;
            P.stat.att += data->inventory.tab[i].item.att;
            P.stat.def += data->inventory.tab[i].item.def;
            P.stat.spd += data->inventory.tab[i].item.spd;
        }
    }
    P.stat.hp = P.stat.hpMax;
}

void switch_items(struct_t *data, int i, int idx)
{
    items_t tmp1 = data->inventory.tab[i].item;
    items_t tmp2 = data->inventory.tab[idx].item;
    sfVector2f pos1 = data->inventory.tab[i].pos;
    sfVector2f pos2 = data->inventory.tab[idx].pos;

    if (data->inventory.tab[i].taken == 1) {
        sfSprite_setPosition(data->inventory.tab[i].item.sprite, pos2);
        sfSprite_setPosition(data->inventory.tab[idx].item.sprite, pos1);
        data->inventory.tab[idx].item = tmp1;
    } else {
        sfSprite_setPosition(data->inventory.tab[idx].item.sprite, pos1);
        init_one_cell(data, idx);
        data->inventory.tab[i].taken = 1;
    }
    data->inventory.tab[i].item = tmp2;
    data->inventory.idx = i;
    fflush(stdout);
}

int check_in_main_item_tab(struct_t *data, sfVector2i posi)
{
    for (int i = 0; i < 36; i++) {
        if (posi.x >= (data->inventory.areaPos[i].x) &&
            posi.x <= (data->inventory.areaPos[i].x + 75)
            && posi.y >= (data->inventory.areaPos[i].y) &&
            posi.y <= (data->inventory.areaPos[i].y + 75)) {
            switch_items(data, i + 5, data->inventory.idx);
            return (1);
        }
    }
    return (0);
}

int item_compatibility(struct_t *data, sfVector2i posi, int i, items_t item)
{
    if ((i == 0 && item.type != 1) || (i == 1 && item.type != 2) ||
        (i == 2 && item.type != 3) || (i == 3 && item.type != 3) ||
        (i == 4 && item.type != 4))
        return (0);
    switch_items(data, i, data->inventory.idx);
    return (1);
}

int check_in_equipment_item_tab(struct_t *data, sfVector2i posi)
{
    items_t item = data->inventory.tab[data->inventory.idx].item;
    int ret = -1;

    for (int i = 0; i < 5; i++) {
        if (posi.x >= (data->inventory.equipmentPos[i].x) &&
            posi.x <= (data->inventory.equipmentPos[i].x + 75)
            && posi.y >= (data->inventory.equipmentPos[i].y) &&
            posi.y <= (data->inventory.equipmentPos[i].y + 75)) {
            ret = item_compatibility(data, posi, i, item);
            return (ret);
        }
    }
    return (0);
}
