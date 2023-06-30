/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** name
*/
#include "../../include/my.h"

void name_loop(struct_t *data, menu_t *menu)
{
    P.stat.Default_hpMax = P.stat.hpMax;
    P.stat.Default_hp = P.stat.hp;
    P.stat.Default_att = P.stat.att;
    P.stat.Default_def = P.stat.def;
    P.stat.Default_spd = P.stat.spd;
    reset_view(data);
    while (data->set == 4) {
        while (sfRenderWindow_pollEvent(WIN, &EVENT))
            name_manage_events(data, menu);
        name_display(data, menu);
    }
}
