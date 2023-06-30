/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** fight_damages
*/
#include "../../include/my.h"

void monster_damages_animation(struct_t *data, fight_t *fight, int n, int dmg)
{
    countdown_t clock;
    char *hp = nbr_to_str(M.old_hp - dmg);

    clock.clock = sfClock_create();
    while (n != 0) {
        clock.time = sfClock_getElapsedTime(clock.clock);
        clock.seconds = clock.time.microseconds / 1000000.0;
        fight_display(data, fight);
        hp = nbr_to_str(M.old_hp - dmg);
        if (clock.seconds > 0.05 && (M.old_hp - dmg) < 0)
            break;
        if (clock.seconds > 0.03 && (M.old_hp - dmg) >= 0) {
            sfText_setString(M.monster_ActualHp.txt, hp);
            sfRenderWindow_drawText(WIN, M.monster_ActualHp.txt, NULL);
            sfClock_restart(clock.clock);
            n--;
            dmg ++;
        }
    }
    sfClock_destroy(clock.clock);
}

void player_damages_animation(struct_t *data, fight_t *fight, int n, int dmg)
{
    countdown_t clock;
    char *hp = nbr_to_str(P.stat.old_hp - dmg);

    clock.clock = sfClock_create();
    while (n != 0) {
        clock.time = sfClock_getElapsedTime(clock.clock);
        clock.seconds = clock.time.microseconds / 1000000.0;
        fight_display(data, fight);
        hp = nbr_to_str(P.stat.old_hp - dmg);
        if (clock.seconds > 0.05 && (P.stat.old_hp - dmg) < 0)
            break;
        if (clock.seconds > 0.03 && (P.stat.old_hp - dmg) >= 0) {
            sfText_setString(fight->player_ActualHp.txt, hp);
            sfRenderWindow_drawText(WIN, fight->player_ActualHp.txt, NULL);
            sfClock_restart(clock.clock);
            n--;
            dmg ++;
        }
    }
    sfClock_destroy(clock.clock);
}
