/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** fight
*/
#include "../../include/my.h"

void get_player_data(struct_t *data, fight_t *fight)
{
    fight->player_ActualHp.str = nbr_to_str(P.stat.hp);
    fight->player_hp.str = nbr_to_str(P.stat.hp);
    fight->player_lvl.str = nbr_to_str(P.stat.lvl);
    fight->player_ActualXp.str = nbr_to_str(P.stat.xp);
    fight->player_xp.str = nbr_to_str(P.stat.xpMax);
    ADS = malloc(sizeof(text_t) * 3);
    ADS[0].str = nbr_to_str(P.stat.att);
    ADS[1].str = nbr_to_str(P.stat.def);
    ADS[2].str = nbr_to_str(P.stat.spd);
    P.stat.hp = P.stat.hp;
    fight->p_att = P.stat.att;
    fight->p_def = P.stat.def;
    fight->p_spd = P.stat.spd;
}

void init_fight_player_part(struct_t *data, fight_t *fight)
{
    get_player_data(data, fight);
    init_player_stats_area(data, fight);
    init_player_attdefspd_texts(fight);
    init_player_name_text(data, fight);
    init_player_hp_text(data, fight);
    init_player_xp_text(data, fight);
}

fight_t *fight_init(struct_t *data)
{
    fight_t *fight = malloc(sizeof(fight_t));

    fight->bg.sprite = sfSprite_create();
    fight->bg.texture = sfTexture_createFromFile("asset/fight_bg.png", NULL);
    sfSprite_setTexture(fight->bg.sprite, fight->bg.texture, sfTrue);
    init_fight_button(fight);
    init_fight_player_part(data, fight);
    init_fight_monster(data, fight);
    init_monster_stats_area(data, fight);
    init_monster_name_text(data, fight);
    init_monster_hp_text(data, fight);
    fight->delay.clock = sfClock_create();
    data->winner = 0;
    return (fight);
}
