/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** player
*/
#include "../../include/my.h"

void init_player_sprite(struct_t *data)
{
    sfVector2f hitbox_pos;

    P.sprite = sfSprite_create();
    P.rect.top = 0;
    P.rect.left = 47;
    P.rect.width = 47;
    P.rect.height = 48;
    P.pos.x = 986;
    P.pos.y = 300;
    sfSprite_setTextureRect(P.sprite, P.rect);
    sfSprite_setPosition(P.sprite, P.pos);
    sfSprite_setScale(P.sprite, (sfVector2f) {0.5, 0.5});
    P.hitbox = sfRectangleShape_create();
    hitbox_pos.x = (P.pos.x + 4);
    hitbox_pos.y = (P.pos.y + 15);
    sfRectangleShape_setPosition(P.hitbox, hitbox_pos);
    sfRectangleShape_setSize(P.hitbox, (sfVector2f) {12, 10});
    sfRectangleShape_setFillColor(P.hitbox, sfTransparent);
    sfRectangleShape_setOutlineColor(P.hitbox, sfRed);
    sfRectangleShape_setOutlineThickness(P.hitbox, 1);
}

void init_player_profile(struct_t *data)
{
    P.profile.sprite = sfSprite_create();
    P.profile.pos.x = P.pos.x - 217;
    P.profile.pos.y = P.pos.y + 95;
    P.profile.scale.x = 0.45;
    P.profile.scale.y = 0.45;
    sfSprite_setPosition(P.profile.sprite, P.profile.pos);
    sfSprite_setScale(P.profile.sprite, P.profile.scale);
}

void init_player(struct_t *data)
{
    init_player_sprite(data);
    P.life = 3;
    P.direction = 3;
    P.tab_x = 5;
    P.tab_y = 10;
    P.clock.clock = sfClock_create();
    P.name = malloc(sizeof(char) * 100);
    init_player_profile(data);
    P.stat.hpMax = 30;
    P.stat.hp = 30;
    P.stat.lvl = 1;
    P.stat.xp = 0;
    P.stat.xpMax = 20;
}
