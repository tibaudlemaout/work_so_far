/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** inventory
*/
#include "../../include/my.h"

void is_on_box(struct_t *data, sfVector2i posi, int i)
{
    sfVector2f obj = sfSprite_getPosition(data->inventory.tab[i].item.sprite);

    if (posi.x >= obj.x && posi.x <= (obj.x + 75) &&
        posi.y >= obj.y && posi.y <= (obj.y + 75)) {
        data->inventory.drag = 1;
        data->inventory.offset.x = posi.x - obj.x;
        data->inventory.offset.y = posi.y - obj.y;
        data->inventory.idx = i;
        data->inventory.OldPos = obj;
    }
}

void check_for_object_position(struct_t *data, sfVector2i posi)
{
    for (int i = 0; i < 41; i++) {
        if (data->inventory.tab[i].taken == 1)
            is_on_box(data, posi, i);
    }
}

void find_correct_area(struct_t *data, sfVector2i posi)
{
    int find_position = 0;
    int idx = data->inventory.idx;
    data->inventory.drag = 0;
    sfVector2f pos = data->inventory.OldPos;

    if (check_in_main_item_tab(data, posi) == 1)
        find_position = 1;
    else if (check_in_equipment_item_tab(data, posi) == 1)
        find_position = 1;
    idx = data->inventory.idx;
    if (find_position == 0)
        sfSprite_setPosition(data->inventory.tab[idx].item.sprite, pos);
    update_player_stats(data, data->inventory.idx);
}

void inventory_manage_events2(struct_t *data, sfVector2i posi)
{
    sfVector2f NewPosition;
    int i = data->inventory.idx;

    if (EVENT.type == sfEvtMouseMoved && data->inventory.drag == 1) {
        NewPosition.x = posi.x - data->inventory.offset.x;
        NewPosition.y = posi.y - data->inventory.offset.y;
        sfSprite_setPosition(data->inventory.tab[i].item.sprite, NewPosition);
    }
}

void inventory_manage_events(struct_t *data)
{
    sfVector2i posi = get_mouse_position(data);

    if (EVENT.type == sfEvtClosed)
        data->set = 0;
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code == sfKeyEscape)
        data->set = 15;
    if (EVENT.type == sfEvtMouseButtonReleased &&
        EVENT.key.code == sfMouseLeft) {
        if (posi.x >= 30 && posi.x <= 130 && posi.y >= 30 && posi.y <= 130)
            data->set = 15;
    }
    if (EVENT.type == sfEvtMouseButtonPressed && EVENT.key.code == sfMouseLeft)
        check_for_object_position(data, posi);
    if (EVENT.type == sfEvtMouseMoved && EVENT.type == sfEvtMouseButtonPressed
        && EVENT.key.code == sfMouseLeft)
        check_for_object_position(data, posi);
    if (EVENT.type == sfEvtMouseButtonReleased &&
        EVENT.key.code == sfMouseLeft && data->inventory.drag == 1)
        find_correct_area(data, posi);
    inventory_manage_events2(data, posi);
}
