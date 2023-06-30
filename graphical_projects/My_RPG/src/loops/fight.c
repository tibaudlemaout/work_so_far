/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** fight
*/
#include "../../include/my.h"

void fight_monster_turn(struct_t *data, fight_t *fight)
{
    int att = M.ads[0];
    int def = fight->p_def;
    int result = att - (def / 100 * att);
    int old_hp = P.stat.hp;

    if (fight->player_turn == 0) {
        fight->delay.time = sfClock_getElapsedTime(fight->delay.clock);
        fight->delay.seconds = fight->delay.time.microseconds / 1000000.0;
        if (fight->delay.seconds > 1.8) {
            att = M.ads[0];
            result = att - (def / 100 * att);
            old_hp = P.stat.hp;
            P.stat.old_hp = old_hp;
            P.stat.hp -= result;
            sfText_setString(fight->player_ActualHp.txt, nbr_to_str(P.stat.hp));
            fight->player_turn = 1;
            player_damages_animation(data, fight, old_hp - P.stat.hp, 1);
            sfClock_restart(fight->delay.clock);
        }
    }
}

int fight_check_end(struct_t *data, fight_t *fight)
{
    if (M.hp <= 0) {
        data->winner = 1;
        data->set = 8;
        return (1);
    }
    fight_monster_turn(data, fight);
    if (P.stat.hp <= 0){
        data->winner = 0;
        data->set = data->old_set;
        return (1);
        // return 1 et data->set = game_over
    }
    return (0);
}

fight_t *fight_loop(struct_t *data)
{
    fight_t *fight = fight_init(data);

    if (fight->monster.ads[3] > fight->p_spd)
        fight->player_turn = 0;
    else
        fight->player_turn = 1;
    while (data->set == 7) {
        while (sfRenderWindow_pollEvent(WIN, &EVENT))
            fight_manage_events(data, fight);
        if (fight_check_end(data, fight) == 1)
            break;
        fight_display(data, fight);
    }
    return (fight);
}
