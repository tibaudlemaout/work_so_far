/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** inventory
*/
#include "../../include/my.h"

void update_inventory_player_stat(struct_t *data)
{
    char *hp = "Hp  ";
    char *att = "Att  ";
    char *def = "Def  ";
    char *spd = "Spd  ";

    hp = my_strcat(hp, nbr_to_str(P.stat.hpMax));
    att = my_strcat(att, nbr_to_str(P.stat.att));
    def = my_strcat(def, nbr_to_str(P.stat.def));
    spd = my_strcat(spd, nbr_to_str(P.stat.spd));
    sfText_setString(data->inventory.player_hads[0], hp);
    sfText_setString(data->inventory.player_hads[1], att);
    sfText_setString(data->inventory.player_hads[2], def);
    sfText_setString(data->inventory.player_hads[3], spd);
}

void update_inventory_item_stat2(struct_t *data, items_t item)
{
    char *def = "Def  ";
    char *spd = "Spd  ";

    def = my_strcat(def, nbr_to_str(item.def));
    spd = my_strcat(spd, nbr_to_str(item.spd));
    if (item.def == 0)
        def = my_strcat(def, "+0");
    else if (item.def > 0)
        def = my_strcat("Def  +", nbr_to_str(item.def));
    else
        def = my_strcat("Def  -", nbr_to_str((item.def * (-1))));
    if (item.spd == 0)
        spd = my_strcat(spd, "+0");
    else if (item.spd > 0)
        spd = my_strcat("Spd  +", nbr_to_str(item.spd));
    else
        spd = my_strcat("Spd  -", nbr_to_str((item.spd * (-1))));
    sfText_setString(data->inventory.item_hads[2], def);
    sfText_setString(data->inventory.item_hads[3], spd);
    sfText_setString(data->inventory.item_name, item.name);
}

void update_inventory_item_stat(struct_t *data, items_t item)
{
    char *hp = "Hp  ";
    char *att = "Att  ";

    hp = my_strcat(hp, nbr_to_str(item.hp));
    att = my_strcat(att, nbr_to_str(item.att));
    if (item.hp == 0)
        hp = my_strcat(hp, "+0");
    else if (item.hp > 0)
        hp = my_strcat("Hp  +", nbr_to_str(item.hp));
    else
        hp = my_strcat("Hp  -", nbr_to_str((item.hp * (-1))));
    if (item.att == 0)
        att = my_strcat(att, "+0");
    else if (item.att > 0)
        att = my_strcat("Att  +", nbr_to_str(item.att));
    else
        att = my_strcat("Att  -", nbr_to_str((item.att * (-1))));
    sfText_setString(data->inventory.item_hads[0], hp);
    sfText_setString(data->inventory.item_hads[1], att);
    update_inventory_item_stat2(data, item);
}

void inventory_loop(struct_t *data)
{
    init_inventory_shadow(data);
    reset_view(data);
    while (data->set == 9) {
        while (sfRenderWindow_pollEvent(WIN, &EVENT))
            inventory_manage_events(data);
        update_inventory_player_stat(data);
        inventory_display(data);
    }
    return;
}
