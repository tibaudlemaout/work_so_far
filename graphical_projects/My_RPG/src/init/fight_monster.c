/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** fight_monster
*/
#include "../../include/my.h"

void init_fight_monster(struct_t *data, fight_t *fight)
{
    char *filepath = data->mob[data->random_mob_nb].profile_filepath;
    M.name = data->mob[data->random_mob_nb].name;
    M.sprite.sprite = sfSprite_create();
    M.sprite.texture = sfTexture_createFromFile(filepath, NULL);
    M.sprite.pos.x = 1000;
    M.sprite.pos.y = 200;
    M.sprite.scale.x = 3.5;
    M.sprite.scale.y = 3.5;
    if (data->random_mob_nb == 5) {
        M.sprite.scale.x = 2.5;
        M.sprite.scale.y = 2.5;
    }
    for (int i = 0; i < 3; i++) {
        M.ads[i] = data->mob[data->random_mob_nb].ads[i];
        M.factor[i] = data->mob[data->random_mob_nb].factor[i];
    }
    M.hp = data->mob[data->random_mob_nb].hp;
    sfSprite_setTexture(M.sprite.sprite, M.sprite.texture, sfTrue);
    sfSprite_setPosition(M.sprite.sprite, M.sprite.pos);
    sfSprite_setScale(M.sprite.sprite, M.sprite.scale);
}
