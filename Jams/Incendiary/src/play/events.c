/*
** EPITECH PROJECT, 2023
** Epitech_Jam_1
** File description:
** events
*/
#include "../../include/struct.h"
#include "../../include/my.h"
#include "../../include/define.h"

void mouvments(struct_t *all, sfEvent *event, int map[11][20])
{
    if (event->type == sfEvtKeyReleased && event->key.code == sfKeyD && map[P.tab_y][P.tab_x + 1] == 0) {
        P.tab_x++;
        P.pos.x += 80;
        P.direction = 2;
        sfSprite_setTexture(P.sprite, P.TextureRight, sfTrue);
        sfSprite_setPosition(P.sprite, P.pos);
    }
    if (event->type == sfEvtKeyReleased && event->key.code == sfKeyQ && map[P.tab_y][P.tab_x - 1] == 0) {
        P.tab_x--;
        P.pos.x -= 80;
        P.direction = 4;
        sfSprite_setTexture(P.sprite, P.TextureLeft, sfTrue);
        sfSprite_setPosition(P.sprite, P.pos);
    }
    if (event->type == sfEvtKeyReleased && event->key.code == sfKeyS && map[P.tab_y + 1][P.tab_x] == 0) {
        P.tab_y++;
        P.pos.y += 80;
        P.direction = 3;
        sfSprite_setTexture(P.sprite, P.TextureDown, sfTrue);
        sfSprite_setPosition(P.sprite, P.pos);
    }
    if (event->type == sfEvtKeyReleased && event->key.code == sfKeyZ && map[P.tab_y - 1][P.tab_x] == 0) {
        P.tab_y--;
        P.pos.y -= 80;
        P.direction = 1;
        sfSprite_setTexture(P.sprite, P.TextureUp, sfTrue);
        sfSprite_setPosition(P.sprite, P.pos);
    }
}

void rotation(struct_t *all, sfEvent *event)
{
    if (event->type == sfEvtKeyReleased && event->key.code == sfKeyRight) {
        P.direction = 2;
        sfSprite_setTexture(P.sprite, P.TextureRight, sfTrue);
    }
    if (event->type == sfEvtKeyReleased && event->key.code == sfKeyLeft) {
        P.direction = 4;
        sfSprite_setTexture(P.sprite, P.TextureLeft, sfTrue);
    }
    if (event->type == sfEvtKeyReleased && event->key.code == sfKeyDown) {
        P.direction = 3;
        sfSprite_setTexture(P.sprite, P.TextureDown, sfTrue);
    }
    if (event->type == sfEvtKeyReleased && event->key.code == sfKeyUp) {
        P.direction = 1;
        sfSprite_setTexture(P.sprite, P.TextureUp, sfTrue);
    }
}

void water_set(struct_t *all)
{
    switch (P.direction) {
        case 1:
            W.pos.x = P.pos.x;
            W.pos.y = P.pos.y - (24 * W.scale.y);
            sfSprite_setPosition(W.sprite, W.pos);
            sfSprite_setTexture(W.sprite, W.TextureUp, sfTrue);
            break;
        case 2:
            W.pos.x = P.pos.x;
            W.pos.y = P.pos.y;
            sfSprite_setPosition(W.sprite, W.pos);
            sfSprite_setTexture(W.sprite, W.TextureRight, sfTrue);
            break;
        case 3:
            W.pos.x = P.pos.x;
            W.pos.y = P.pos.y;
            sfSprite_setPosition(W.sprite, W.pos);
            sfSprite_setTexture(W.sprite, W.TextureDown, sfTrue);
            break;
        case 4:
            W.pos.x = P.pos.x - (24 * W.scale.x);
            W.pos.y = P.pos.y;
            sfSprite_setPosition(W.sprite, W.pos);
            sfSprite_setTexture(W.sprite, W.TextureLeft, sfTrue);
            break;
    }
}

void game_manage_events(struct_t *all, sprite_t *fire, sfEvent *event, int map[11][20])
{
    if (event->type == sfEvtClosed)
        all->set = 0;
    
    mouvments(all, event, map);
    rotation(all, event);
    
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeySpace) {
        W.life = 1;
        water_set(all);
        fire_detection(all, fire);
    }
    if (event->type == sfEvtKeyReleased && event->key.code == sfKeySpace)
        W.life = 0;
}