/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** finishing_fight
*/
#include "../../include/my.h"

void get_xp(struct_t *data)
{
    float percent = 1.25;

    if (data->area == 1)
        P.stat.xp += 5;
    if (data->area == 2)
        P.stat.xp += 10;
    if (data->area == 3)
        P.stat.xp += 15;
    if (P.stat.xp >= P.stat.xpMax) {
        P.stat.lvl++;
        P.stat.xpMax *= ((percent * P.stat.xpMax) / 100);
        P.stat.xp = 0;
        P.stat.Default_hpMax += 3;
        P.stat.Default_att += 1;
        P.stat.Default_def += 1;
        P.stat.Default_spd += 1;
    }
    return;
}

int get_fight_loot(struct_t *data, fight_t *fight)
{
    // int drop = rand() % 100;
    int drop = rand() % 59;
    int item_index = -1;

    if (data->winner == 1) {
        if (drop <= 40)
            item_index = get_universal_loot(data, drop);
        else
            item_index = get_area_loot(data, drop);
        if (item_index != -1)
            set_loot_into_inventory(data, item_index);
        get_xp(data);
        printf("xp : %d\n", P.stat.xp);
    }
    return (item_index);
}

void finishing_fight_clock(struct_t *data, countdown_t clock)
{
    clock.time = sfClock_getElapsedTime(clock.clock);
    clock.seconds = clock.time.microseconds / 1000000.0;
    if (clock.seconds > 3)
        data->set = data->old_set;
}

void display_looting(struct_t *data, fight_t *fight, looting_t *looting, int i)
{
    sfRenderWindow_clear(WIN, sfBlack);
    sfRenderWindow_setView(WIN, data->view);
    sfRenderWindow_drawSprite(WIN, looting->bg.sprite, NULL);
    sfRenderWindow_drawRectangleShape(WIN, looting->rect, NULL);
    sfRenderWindow_drawText(WIN, looting->str, NULL);
    if (i != -1) {
        sfRenderWindow_drawSprite(WIN, looting->loot_sprite, NULL);
        sfRenderWindow_drawText(WIN, looting->loot_name, NULL);
    }
    sfRenderWindow_display(WIN);
}

void finishing_fight_animation(struct_t *data, fight_t *fight)
{
    countdown_t clock;
    int item_index = get_fight_loot(data, fight);
    looting_t *looting = init_finishing_fight(data, item_index);

    for (int i = 0; i < 41; i++)
        update_player_stats(data, i);
    clock.clock = sfClock_create();
    while (data->set == 8) {
        while (sfRenderWindow_pollEvent(WIN, &EVENT))
            fight_animation_manage_events(data);
        display_looting(data, fight, looting, item_index);
        finishing_fight_clock(data, clock);
    }
    sfView_destroy(data->view);
    sfClock_destroy(clock.clock);
    return;
}
