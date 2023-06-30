/*
** EPITECH PROJECT, 2023
** GGJ
** File description:
** game
*/
#include "../../include/struct.h"
#include "../../include/my.h"
#include "../../include/define.h"

void draw_game(struct_t *all, sprite_t *fire, sprite_t *obj)
{
    sfRenderWindow_drawSprite(WIN, all->bg.sprite, NULL);
    while (obj != NULL)  {
        if (obj->display == 1 && obj->life > 0)
            sfRenderWindow_drawSprite(WIN, obj->sprite, NULL);
        obj = obj->next;
    }
    sfRenderWindow_drawSprite(WIN, P.sprite, NULL);
    if (W.life == 1)
        sfRenderWindow_drawSprite(WIN, W.sprite, NULL);
    while (fire != NULL)  {
        if (fire->display == 1 && fire->life > 0)
            sfRenderWindow_drawSprite(WIN, fire->sprite, NULL);
        fire = fire->next;
    }
    sfRenderWindow_drawSprite(WIN, all->walls.sprite, NULL);
    sfRenderWindow_drawSprite(WIN, all->smoke.sprite, NULL);
    sfRenderWindow_drawSprite(WIN, all->hourglass.sprite, NULL);
    sfRenderWindow_drawText(WIN, all->countdown.text, NULL);
    sfRenderWindow_drawSprite(WIN, all->pv.sprite, NULL);
}

void check_damage(struct_t *all, sprite_t *fire)
{
    sfVector2f scale = {2, 2};
    sfSprite *hit = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("asset/backgrounds/hit.png", NULL);
    sfSprite_setTexture(hit, texture, sfTrue);
    sfSprite_setScale(hit, scale);
    all->damage.time = sfClock_getElapsedTime(all->damage.clock);
    all->damage.seconds = all->damage.time.microseconds / 1000000.0;
    if (all->damage.seconds > 1.0) {
        while (fire != NULL) {
            if (fire->pos.x == P.pos.x && fire->pos.y == P.pos.y && fire->display == 1 && fire->life > 0) {
                P.life--;
                if (all->player.life == 2)
                    all->pv.texture = sfTexture_createFromFile("asset/pv/pv02.png", NULL);
                if (all->player.life == 1)
                    all->pv.texture = sfTexture_createFromFile("asset/pv/pv01.png", NULL);
                if (all->player.life <= 0)
                    all->pv.texture = sfTexture_createFromFile("asset/pv/pv00.png", NULL);
                sfSprite_setTexture(all->pv.sprite, all->pv.texture, sfTrue);
                sfRenderWindow_drawSprite(WIN, all->pv.sprite, NULL);
                sfRenderWindow_drawSprite(WIN, hit, NULL);
                sfRenderWindow_drawSprite(WIN, hit, NULL);
                sfRenderWindow_drawSprite(WIN, hit, NULL);
            }
            fire = fire->next;
        }
        sfClock_restart(all->damage.clock);
    }
    sfSprite_destroy(hit);
    sfTexture_destroy(texture);
}

int check_win(struct_t *all, sprite_t *fire)
{
    int cmp = 0;

    while (fire != NULL)  {
        if (fire->life <= 0)
            cmp++;
        fire = fire->next;
    }
    if (cmp == all->fire_nb)
        return 1;
    return 0;
}

void play_game(struct_t *all, sfEvent *event)
{
    sprite_t *fire = NULL;
    sprite_t *obj = NULL;
    init_game(all, &fire, &obj);
    int map[11][20] = {
        {11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
        {11, 5, 3, 3, 9, 0, 0, 0, 6, 6, 2, 11, 4, 10, 0, 2, 1, 1, 5, 11},
        {11, 0, 0, 0, 0, 0, 0, 2, 6, 6, 0, 11, 0, 0, 0, 0, 1, 1, 0, 11},
        {11, 8, 7, 7, 0, 0, 0, 0, 0, 0, 0, 11, 8, 0, 0, 0, 0, 0, 0, 11},
        {11, 11, 11, 11, 11, 0, 0, 11, 11, 11, 11, 11, 0, 0, 0, 0, 0, 7, 7, 11},
        {11, 11, 11, 11, 11, 0, 0, 11, 11, 11, 11, 11, 11, 0, 11, 11, 11, 11, 11, 11},
        {11, 2, 7, 7, 10, 0, 0, 0, 0, 4, 5, 11, 11, 0, 11, 11, 11, 11, 11, 11},
        {11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 4, 5, 5, 11},
        {11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11},
        {11, 10, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 11},
        {11, 11, 11, 11, 11, 0, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11}};
    while (all->set == 3) {
        sfRenderWindow_display(WIN);
        sfRenderWindow_clear(WIN, sfBlue);

        draw_game(all, fire, obj);
        countdown(all, fire);
        check_damage(all, fire);
        
        if (P.life < 1 || all->hourglass.life < 1 || all->delay.seconds > 80)
            all->set = 4;
        if (check_win(all, fire) == 1)
            all->set = 5;

        while (sfRenderWindow_pollEvent(WIN, event))
            game_manage_events(all, fire, event, map);
    }
}
