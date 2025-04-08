/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file fork.c
 * @brief File containing functions for the fork object AI command to
 *  lay an egg
*/

#include "../../include/zappy_server.h"

/**
 * @brief function that is first called for the fork object AI command
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void start_fork(player_t *player, char **args, info_t *info)
{
    (void)args;
    (void)info;
    (void)GUI_COMMANDS;
    player->time_start = clock();
}

/**
 * @brief function that is first called for the fork object AI command
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void fork_player(player_t *player, char **args, info_t *info)
{
    char str[48];
    player_t egg;

    (void)args;
    create_egg(&egg, player->team_name, info, player->position);
    append_to_string(player->w_buffer, "ok\n");
    enqueue_command_front(&egg, NULL, &PLAYER_COMMANDS[12]);
    set_time(&egg);
    append_player_node(&info->head_player, egg);
    info->next_id++;
    sprintf(str, "enw %d %d %d %d\n", player->id, egg.id,
        player->position.x, player->position.y);
    append_to_gui(info, str);
}
