/*
** EPITECH PROJECT, 2023
** Epitech_Jam_1
** File description:
** get_script
*/
#include "../../include/struct.h"
#include "../../include/my.h"
#include "../../include/define.h"

void add_fire(struct_t *all, sprite_t **fire)
{
    sprite_t *new_fire = malloc(sizeof(sprite_t));
    new_fire->sprite = sfSprite_create();
    new_fire->texture = sfTexture_createFromFile("asset/fire.png", NULL);
    new_fire->pos.x = all->tmp_x;
    new_fire->pos.y = all->tmp_y;
    new_fire->delay = all->tmp_delay;
    new_fire->scale.x = 5;
    new_fire->scale.y = 5;
    new_fire->display = 0;
    new_fire->life = 1;
    sfSprite_setTexture(new_fire->sprite, new_fire->texture, sfFalse);
    sfSprite_setPosition(new_fire->sprite, new_fire->pos);
    sfSprite_setScale(new_fire->sprite, new_fire->scale);
    new_fire->next = (*fire);
    (*fire) = new_fire;
}

void get_fire_script(struct_t *all, char *buffer, int i)
{
    i += 2;
    all->tmp_x = my_get_nbr(i, buffer);
    for (i; buffer[i] != ' '; i++);
    for (i; buffer[i] == ' '; i++);
    all->tmp_y = my_get_nbr(i, buffer);
    for (i; buffer[i] != ' '; i++);
    for (i; buffer[i] == ' '; i++);
    all->tmp_delay = my_get_nbr(i, buffer);
}

void add_object(struct_t *all, sprite_t **obj)
{
    sprite_t *new_obj = malloc(sizeof(sprite_t));
    new_obj->sprite = sfSprite_create();
    new_obj->texture = sfTexture_createFromFile(all->tmp_filepath, NULL);
    new_obj->pos.x = all->tmp_x;
    new_obj->pos.y = all->tmp_y;
    new_obj->scale.x = all->tmp_scale;
    new_obj->scale.y = all->tmp_scale;
    new_obj->display = 1;
    new_obj->life = 5;
    sfSprite_setTexture(new_obj->sprite, new_obj->texture, sfFalse);
    sfSprite_setPosition(new_obj->sprite, new_obj->pos);
    sfSprite_setScale(new_obj->sprite, new_obj->scale);
    new_obj->next = (*obj);
    (*obj) = new_obj;
}

void get_object_script(struct_t *all, char *buffer, int i)
{
    i += 2;
    switch (my_get_nbr(i, buffer)) {
        case 0: all->tmp_filepath = "asset/furnitures/plant.png"; break;
        case 1: all->tmp_filepath = "asset/furnitures/bed.png"; break;
        case 2: all->tmp_filepath = "asset/furnitures/chair.png"; break;
        case 3: all->tmp_filepath = "asset/furnitures/couch.png"; break;
        case 4: all->tmp_filepath = "asset/furnitures/drawer.png"; break;
        case 5: all->tmp_filepath = "asset/furnitures/library.png"; break;
        case 6: all->tmp_filepath = "asset/furnitures/table.png"; break;
        case 7: all->tmp_filepath = "asset/furnitures/table_1.png"; break;
        case 8: all->tmp_filepath = "asset/furnitures/stool.png"; break;
        case 9: all->tmp_filepath = "asset/furnitures/sitting_chair.png"; break;
    }
    for (i; buffer[i] != ' '; i++);
    for (i; buffer[i] == ' '; i++);
    all->tmp_x = my_get_nbr(i, buffer);
    for (i; buffer[i] != ' '; i++);
    for (i; buffer[i] == ' '; i++);
    all->tmp_y = my_get_nbr(i, buffer);
    for (i; buffer[i] != ' '; i++);
    for (i; buffer[i] == ' '; i++);
    all->tmp_scale = my_get_nbr(i, buffer);
}
