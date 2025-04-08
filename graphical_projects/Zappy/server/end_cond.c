/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** condition for end of loop
*/
#include "include/zappy_server.h"

static int is_max_lvl(linked_player_t *tmp, info_t *info, int i)
{
    int lvl_8 = 0;

    while (tmp != NULL) {
        if (strcmp(tmp->player.team_name, info->teams[i]) == 0 &&
            tmp->player.level == 8)
            lvl_8++;
        tmp = tmp->next;
    }
    return (lvl_8);
}

bool end_cond(info_t *info)
{
    int lvl_8 = 0;
    char str[128] = "";
    linked_player_t *tmp = info->head_player;

    for (int i = 0; info->teams[i]; i++) {
        lvl_8 = is_max_lvl(tmp, info, i);
        if (lvl_8 >= 6) {
            sprintf(str, "seg %s\n", info->teams[i]);
            append_to_gui(info, str);
            return (true);
        }
        lvl_8 = 0;
        tmp = info->head_player;
    }
    return (false);
}
