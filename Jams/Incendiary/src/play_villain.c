/*
** EPITECH PROJECT, 2023
** Epitech_Jam_1
** File description:
** play_villain
*/
#include "../include/struct.h"
#include "../include/my.h"
#include "../include/define.h"

void init_match(struct_t *all)
{
    all->match.texture = sfTexture_createFromFile("asset/match.png", NULL);
    all->match.sprite = sfSprite_create();
    all->match.scale.x = 5;
    all->match.scale.y = 5;
    all->match.pos.x = 1125;
    all->match.pos.y = 400;

    sfSprite_setTexture(all->match.sprite, all->match.texture, sfTrue);
    sfSprite_setScale(all->match.sprite, all->match.scale);
    sfSprite_setPosition(all->match.sprite, all->match.pos);
}

void init_anim(struct_t *all)
{
    all->anim_bg.sprite = sfSprite_create();
    all->anim_bg.texture = sfTexture_createFromFile("asset/backgrounds/VillainAnim2.png", NULL);
    all->anim_bg.scale.x = 13.5;
    all->anim_bg.scale.y = 13.5;
    sfSprite_setTexture(all->anim_bg.sprite, all->anim_bg.texture, sfFalse);
    sfSprite_setScale(all->anim_bg.sprite, all->anim_bg.scale);
    init_match(all);
    all->anim_clock.clock = sfClock_create();
}

void villain_manage_event(struct_t *all, sfEvent *event)
{
    if (event->type == sfEvtClosed) {
        all->set = 0;
    }
    return;
}

void clock_villain(struct_t *all)
{
    all->anim_clock.time = sfClock_getElapsedTime(all->anim_clock.clock);
    all->anim_clock.seconds = all->anim_clock.time.microseconds / 1000000.0;
    if (all->anim_clock.seconds > 0.01) {
        all->match.pos.y += 5;
        sfSprite_setPosition(all->match.sprite, all->match.pos);
        sfClock_restart(all->anim_clock.clock);
    }
}

void play_villain(struct_t *all, sfEvent *event)
{
    init_anim(all);
    while (all->set == 6) {
        sfRenderWindow_display(WIN);
        sfRenderWindow_clear(WIN, sfBlack);

        clock_villain(all);
        sfRenderWindow_drawSprite(WIN, all->anim_bg.sprite, NULL);
        sfRenderWindow_drawSprite(WIN, all->match.sprite, NULL);
        
        if (all->match.pos.y > 820)
            all->set = 3;

        while (sfRenderWindow_pollEvent(WIN, event)) {
            villain_manage_event(all, event);
        }
    }
    return;
}
