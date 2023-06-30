/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** fight_player_stats_texts
*/
#include "../../include/my.h"

void init_player_attdefspd_texts(fight_t *fight)
{
    sfVector2f pos = {1675, 830};
    char *att = ADS[0].str;
    char *def = ADS[1].str;
    char *spd = ADS[2].str;

    for (int i = 0; i < 3; i++) {
        sfFont *font = sfFont_createFromFile("asset/BreatheFire.otf");
        ADS[i].txt = sfText_create();
        sfText_setFont(ADS[i].txt, font);
        sfText_setPosition(ADS[i].txt, pos);
        sfText_setColor(ADS[i].txt, sfBlack);
        sfText_setCharacterSize(ADS[i].txt, 40);
        pos.y += 60;
    }
    sfText_setString(ADS[0].txt, my_strcat("Att    ", att));
    sfText_setString(ADS[1].txt, my_strcat("Def    ", def));
    sfText_setString(ADS[2].txt, my_strcat("Spd    ", spd));
}

void init_player_name_text(struct_t *data, fight_t *fight)
{
    sfFont *font = sfFont_createFromFile("asset/BreatheFire.otf");
    fight->player_name.txt = sfText_create();
    sfText_setFont(fight-> player_name.txt, font);
    sfText_setPosition(fight-> player_name.txt, (sfVector2f) {1375, 810});
    sfText_setColor(fight->player_name.txt, sfBlack);
    sfText_setCharacterSize(fight->player_name.txt, 50);
    sfText_setString(fight->player_name.txt, P.name);
}

void init_player_hp_text(struct_t *data, fight_t *fight)
{
    char *s = "HP :                    /";
    sfFont *font = sfFont_createFromFile("asset/BreatheFire.otf");
    fight->player_hp.txt = sfText_create();
    sfText_setFont(fight->player_hp.txt, font);
    sfText_setPosition(fight->player_hp.txt, (sfVector2f) {1375, 925});
    sfText_setColor(fight->player_hp.txt, sfBlack);
    sfText_setCharacterSize(fight->player_hp.txt, 30);
    sfText_setString(fight->player_hp.txt, my_strcat(s, fight->player_hp.str));
    fight->player_ActualHp.txt = sfText_create();
    sfText_setFont(fight->player_ActualHp.txt, font);
    sfText_setPosition(fight->player_ActualHp.txt, (sfVector2f) {1500, 905});
    sfText_setColor(fight->player_ActualHp.txt, sfRed);
    sfText_setCharacterSize(fight->player_ActualHp.txt, 50);
    sfText_setString(fight->player_ActualHp.txt, nbr_to_str(P.stat.hp));
}

void init_player_xp_text(struct_t *data, fight_t *fight)
{
    char *str = my_strcat("XP :          ", fight->player_ActualXp.str);
    str = my_strcat(str, " /");
    str = my_strcat(str, fight->player_xp.str);
    sfFont *font = sfFont_createFromFile("asset/BreatheFire.otf");
    fight->player_xp.txt = sfText_create();
    sfText_setFont(fight->player_xp.txt, font);
    sfText_setPosition(fight->player_xp.txt, (sfVector2f) {1375, 975});
    sfText_setColor(fight->player_xp.txt, sfBlack);
    sfText_setCharacterSize(fight->player_xp.txt, 30);
    sfText_setString(fight->player_xp.txt, str);
}
