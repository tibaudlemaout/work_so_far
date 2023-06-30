/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** lib4
*/
#include "../include/my.h"

void set_item_position(struct_t *data, int i)
{
    sfVector2f pos = data->inventory.tab[i].pos;

    sfSprite_setPosition(data->inventory.tab[i].item.sprite, pos);
    return;
}

void set_loot_into_inventory(struct_t *data, int index)
{
    for (int i = 5; i < 41; i++) {
        if (data->inventory.tab[i].item.nb == data->item[index].nb)
            return;
    }
    for (int i = 5; i < 41; i++) {
        if (data->inventory.tab[i].taken == 0) {
            data->inventory.tab[i].taken = 1;
            data->inventory.tab[i].item = data->item[index];
            set_item_position(data, i);
            return;
        }
    }
    return;
}
