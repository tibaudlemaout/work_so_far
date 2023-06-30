/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** inventory
*/
#include "../../include/my.h"

void init_inventory_areas(struct_t *data, sfColor grey)
{
    sfVector2f size = {75, 75};
    sfVector2f pos = {1100, 330};
    sfColor dark_grey = sfColor_fromRGBA(0, 0, 0, 100);

    data->inventory.area = malloc(sizeof(sfRectangleShape *) * 36);
    data->inventory.areaPos = malloc(sizeof(sfVector2f *) * 36);
    for (int i = 0; i < 36; i++) {
        data->inventory.area[i] = sfRectangleShape_create();
        sfRectangleShape_setFillColor(data->inventory.area[i], dark_grey);
        sfRectangleShape_setOutlineColor(data->inventory.area[i], grey);
        sfRectangleShape_setOutlineThickness(data->inventory.area[i], 3);
        sfRectangleShape_setSize(data->inventory.area[i], size);
        sfRectangleShape_setPosition(data->inventory.area[i], pos);
        data->inventory.areaPos[i] = pos;
        pos.x += (size.x + 3);
        if (i == 5 || i == 11 || i == 17 || i == 23 || i == 29) {
            pos.x = 1100;
            pos.y += (size.y + 3);
        }
    }
}

void init_inventory_equipment_areas(struct_t *data, sfColor grey)
{
    sfVector2f pos;
    sfVector2f size = {75, 75};
    sfColor dark_grey = sfColor_fromRGBA(0, 0, 0, 100);
    double xpos[5] = {500, 250, 250, 500, 500};
    double ypos[5] = {350, 430, 530, 530, 700};

    data->inventory.equipment = malloc(sizeof(sfRectangleShape *) * 5);
    data->inventory.equipmentPos = malloc(sizeof(sfVector2f) * 5);
    for (int i = 0; i < 5; i++) {
        data->inventory.equipment[i] = sfRectangleShape_create();
        sfRectangleShape_setFillColor(data->inventory.equipment[i], dark_grey);
        sfRectangleShape_setOutlineColor(data->inventory.equipment[i], grey);
        sfRectangleShape_setOutlineThickness(data->inventory.equipment[i], 3);
        sfRectangleShape_setSize(data->inventory.equipment[i], size);
        pos.x = xpos[i];
        pos.y = ypos[i];
        data->inventory.equipmentPos[i] = pos;
        data->inventory.tab[i].pos = pos;
        sfRectangleShape_setPosition(data->inventory.equipment[i], pos);
    }
}

void init_inventory_shadow(struct_t *data)
{
    sfTexture *texture;
    sfVector2f pos;

    if (data->avatar == 1 || data->avatar == 3) {
        texture = sfTexture_createFromFile("asset/player/ShadowH.png", NULL);
        pos.x = 345;
    } else {
        texture = sfTexture_createFromFile("asset/player/ShadowW.png", NULL);
        pos.x = 350;
    }
    pos.y = 320;
    sfSprite_setTexture(data->inventory.shadow.sprite, texture, sfTrue);
    sfSprite_setPosition(data->inventory.shadow.sprite, pos);
    data->inventory.OldPos.x = 450;
    data->inventory.OldPos.y = 250;
    data->inventory.drag = 0;
}

void init_inventory(struct_t *data)
{
    sfTexture *texture = sfTexture_createFromFile("asset/Inventory.jpg", NULL);
    int idx = 0;

    data->inventory.tab = malloc(sizeof(tab_t) * 41);
    data->inventory.idx = 0;
    init_inventory_areas(data, sfColor_fromRGB(160, 160, 160));
    init_inventory_equipment_areas(data, sfColor_fromRGB(160, 160, 160));
    for (int i = 0; i < 5; i++)
        init_one_cell(data, i);
    for (int i = 5; i < 41; i++) {
        init_one_cell(data, i);
        data->inventory.tab[i].pos = data->inventory.areaPos[idx];
        idx++;
    }
    data->inventory.bg.sprite = sfSprite_create();
    sfSprite_setTexture(data->inventory.bg.sprite, texture, sfTrue);
    data->inventory.shadow.sprite = sfSprite_create();
    sfSprite_setScale(data->inventory.shadow.sprite, (sfVector2f) {0.8, 0.8});
    init_inventory_player_stat_txt(data);
    init_inventory_item_stat_txt(data);
}
