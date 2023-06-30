/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** fight_monster_stats_texts
*/
#include "../../include/my.h"

void init_monster_name_text(struct_t *data, fight_t *fight)
{
    sfFont *font = sfFont_createFromFile("asset/BreatheFire.otf");
    M.txt_name.txt = sfText_create();
    sfText_setFont(M.txt_name.txt, font);
    sfText_setPosition(M.txt_name.txt, (sfVector2f) {150, 130});
    sfText_setColor(M.txt_name.txt, sfBlack);
    sfText_setCharacterSize(M.txt_name.txt, 50);
    sfText_setString(M.txt_name.txt, M.name);
}

void init_monster_hp_text(struct_t *data, fight_t *fight)
{
    M.monster_ActualHp.str = nbr_to_str(M.hp);
    M.monster_hp.str = nbr_to_str(M.hp);

    char *str = "HP :                    /";
    sfFont *font = sfFont_createFromFile("asset/BreatheFire.otf");
    M.monster_hp.txt = sfText_create();
    sfText_setFont(M.monster_hp.txt, font);
    sfText_setPosition(M.monster_hp.txt, (sfVector2f) {250, 245});
    sfText_setColor(M.monster_hp.txt, sfBlack);
    sfText_setCharacterSize(M.monster_hp.txt, 30);
    sfText_setString(M.monster_hp.txt, my_strcat(str, M.monster_hp.str));
    M.monster_ActualHp.txt = sfText_create();
    sfText_setFont(M.monster_ActualHp.txt, font);
    sfText_setPosition(M.monster_ActualHp.txt, (sfVector2f) {350, 225});
    sfText_setColor(M.monster_ActualHp.txt, sfRed);
    sfText_setCharacterSize(M.monster_ActualHp.txt, 50);
    sfText_setString(M.monster_ActualHp.txt, M.monster_ActualHp.str);
}
