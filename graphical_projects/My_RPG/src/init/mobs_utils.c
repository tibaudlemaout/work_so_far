/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** mobs_utils
*/
#include "../../include/my.h"

void init_mob_move_sprite(mobs_t *mob, char *name)
{
    char *str = my_strcat("asset/mobs/", name);
    char *Down = my_strcat(str, "Down.png");
    char *Up = my_strcat(str, "Up.png");
    char *Right = my_strcat(str, "Right.png");
    char *Left = my_strcat(str, "Left.png");
    sfIntRect rect = {47, 0, 47, 48};

    mob->sprite = sfSprite_create();
    mob->TextureDown = sfTexture_createFromFile(Down, NULL);
    mob->TextureUp = sfTexture_createFromFile(Up, NULL);
    mob->TextureRight = sfTexture_createFromFile(Right, NULL);
    mob->TextureLeft = sfTexture_createFromFile(Left, NULL);
    mob->pos.x = 500;
    mob->pos.y = 500;
    sfSprite_setTexture(mob->sprite, mob->TextureDown, sfTrue);
    sfSprite_setTextureRect(mob->sprite, rect);
    sfSprite_setPosition(mob->sprite, mob->pos);
    sfSprite_setScale(mob->sprite, (sfVector2f) {0.5, 0.5});
}
