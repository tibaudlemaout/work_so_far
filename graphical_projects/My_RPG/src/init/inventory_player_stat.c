/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** inventory_player_stat
*/
#include "../../include/my.h"

void set_player_stat_txt(struct_t *data, char *att, char *def, char *spd)
{
    sfFont *font = sfFont_createFromFile("asset/BreatheFire.otf");
    sfVector2f pos = {350, 850};

    data->inventory.player_hads = malloc(sizeof(sfText *) * 4);
    for (int i = 0; i < 4; i++) {
        data->inventory.player_hads[i] = sfText_create();
        sfText_setFont(data->inventory.player_hads[i], font);
        sfText_setColor(data->inventory.player_hads[i], sfBlack);
        sfText_setCharacterSize(data->inventory.player_hads[i], 50);
        sfText_setPosition(data->inventory.player_hads[i], pos);
        pos.x += 300;
    }
}

void init_inventory_player_stat_txt(struct_t *data)
{
    char *att = "Att  ";
    char *def = "Def  ";
    char *spd = "Spd  ";

    att = my_strcat(att, nbr_to_str(P.stat.att));
    def = my_strcat(def, nbr_to_str(P.stat.def));
    spd = my_strcat(spd, nbr_to_str(P.stat.spd));
    set_player_stat_txt(data, att, def, spd);
}
