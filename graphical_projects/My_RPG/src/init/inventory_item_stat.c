/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** inventory_item_stat
*/
#include "../../include/my.h"

void init_inventory_item_stat_txt(struct_t *data)
{
    sfFont *font = sfFont_createFromFile("asset/BreatheFire.otf");
    sfVector2f pos = {620, 330};

    data->inventory.item_name = sfText_create();
    sfText_setFont(data->inventory.item_name, font);
    sfText_setColor(data->inventory.item_name, sfBlack);
    sfText_setCharacterSize(data->inventory.item_name, 50);
    sfText_setPosition(data->inventory.item_name, (sfVector2f) {pos.x, pos.y});
    data->inventory.item_hads = malloc(sizeof(sfText *) * 4);
    pos.y += 120;
    for (int i = 0; i < 4; i++) {
        data->inventory.item_hads[i] = sfText_create();
        sfText_setFont(data->inventory.item_hads[i], font);
        sfText_setColor(data->inventory.item_hads[i], sfBlack);
        sfText_setCharacterSize(data->inventory.item_hads[i], 40);
        sfText_setPosition(data->inventory.item_hads[i], pos);
        pos.y += 75;
    }
}
