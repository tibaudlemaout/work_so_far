/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** inventory
*/
#include "../../include/my.h"

void display_inventory_cells_n_items(struct_t *data)
{
    sfSprite *item;
    sfRectangleShape *box;

    for (int i = 0; i < 36; i++)
        sfRenderWindow_drawRectangleShape(WIN, data->inventory.area[i], NULL);
    for (int i = 0; i < 5; i++) {
        box = data->inventory.equipment[i];
        sfRenderWindow_drawRectangleShape(WIN, box, NULL);
    }
    for (int i = 0; i < 41; i++) {
        if (data->inventory.tab[i].taken == 1) {
            item = data->inventory.tab[i].item.sprite;
            sfRenderWindow_drawSprite(WIN, item, NULL);
        }
    }
}

void display_item_stats(struct_t *data, int i)
{
    sfVector2i posi = get_mouse_position(data);
    sfVector2f obj;

    if (data->inventory.tab[i].taken == 1) {
        obj = sfSprite_getPosition(data->inventory.tab[i].item.sprite);
        if (posi.x >= obj.x && posi.x <= (obj.x + 75) &&
            posi.y >= obj.y && posi.y <= (obj.y + 75)) {
            update_inventory_item_stat(data, data->inventory.tab[i].item);
            sfRenderWindow_drawText(WIN, data->inventory.item_name, NULL);
            sfRenderWindow_drawText(WIN, data->inventory.item_hads[0], NULL);
            sfRenderWindow_drawText(WIN, data->inventory.item_hads[1], NULL);
            sfRenderWindow_drawText(WIN, data->inventory.item_hads[2], NULL);
            sfRenderWindow_drawText(WIN, data->inventory.item_hads[3], NULL);
        }
    }
}

void display_inventory_txt(struct_t *data)
{
    int idx = data->inventory.idx;
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawText(WIN, data->inventory.player_hads[i], NULL);
    if (data->inventory.drag == 0) {
        for (int i = 0; i < 41; i++)
            display_item_stats(data, i);
    } else {
        update_inventory_item_stat(data, data->inventory.tab[idx].item);
        sfRenderWindow_drawText(WIN, data->inventory.item_name, NULL);
        sfRenderWindow_drawText(WIN, data->inventory.item_hads[0], NULL);
        sfRenderWindow_drawText(WIN, data->inventory.item_hads[1], NULL);
        sfRenderWindow_drawText(WIN, data->inventory.item_hads[2], NULL);
        sfRenderWindow_drawText(WIN, data->inventory.item_hads[3], NULL);
    }
}

void inventory_display(struct_t *data)
{
    sfSprite *item;
    sfRectangleShape *box;

    sfRenderWindow_clear(WIN, sfBlack);
    sfRenderWindow_setView(WIN, data->view);
    sfRenderWindow_drawSprite(WIN, data->inventory.bg.sprite, NULL);
    sfRenderWindow_drawSprite(WIN, data->inventory.shadow.sprite, NULL);
    display_inventory_txt(data);
    display_inventory_cells_n_items(data);
    sfRenderWindow_drawSprite(WIN, data->icon[0], NULL);
    sfRenderWindow_display(WIN);
}
