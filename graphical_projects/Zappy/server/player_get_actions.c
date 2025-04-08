/*
** EPITECH PROJECT, 2024
** zappytest
** File description:
** player_get_actions
*/

/**
 * @file player_get_actions.c
 * @brief Unused function pointer for AI parsing
*/

#include <string.h>
#include <stdbool.h>
#include "include/zappy_server.h"
#include "include/players.h"

const action_map_t action_map[] = {
    {"Forward", action_go_forward},
    {"Right", action_turn_right},
    {"Left", action_turn_left},
    {"Look", action_look_around},
    {"Inventory", action_inventory},
    {"Broadcast text", action_broadcast_text},
    {"Connect_nbr", action_unused_teams},
    {"Fork", action_player_fork},
    {"Eject", action_eject_players},
    {"Take object", action_take_object},
    {"Set object", action_set_down},
    {"Incantation", action_incantation},
    {NULL, NULL}
};

/**
 * @brief function that calls different function based on the 1st string
 * @param str the string on which is based the analysis
 * @param engine the old main game structure containing all informations
*/
void player_get_actions(char *str, game_t *engine)
{
    for (int i = 0; action_map[i].command != NULL; i++) {
        if (strcmp(action_map[i].command, str) == 0) {
            return action_map[i].func(str, engine);
        }
    }
    action_unknown(str, engine);
}
