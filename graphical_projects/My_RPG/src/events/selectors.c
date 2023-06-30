/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** selectors
*/
#include "../../include/my.h"

void is_npc_for_quest(struct_t *data, sfRectangleShape *rect, int set)
{
    if (set == 0)
        is_npc_for_quest_tuto(data, rect);
    if (set == 1)
        is_npc_for_quest_area1(data, rect);
    if (set == 2)
        is_npc_for_quest_dungeon1(data, rect);
}

int progress_check(struct_t *data, sfVector2f pos, int set)
{
    if (set == 0)
        return (tuto_progress_check(data, pos));
    if (set == 1)
        return (area1_progress_check(data, pos));
    if (set == 2)
        return (dungeon1_progress_check(data, pos));
}
