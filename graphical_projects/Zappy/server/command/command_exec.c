/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file command_exec.c
 * @brief File containing functions for command execution
*/

#include "../include/zappy_server.h"

/**
 * @brief function that executes the first given command
 * @param player a pointer to a structure corresponding to one player
 * @param info a pointer to a client structure containing all infos
 *  about the game
*/
bool exec_first_func(player_t *player, info_t *info)
{
    if (player->time_start == READY_FIRST_COMMAND) {
        if (strcmp(player->team_name, "GRAPHIC") == 0)
            printf("graphic cmd = %s\n", player->command[0]->cmd);
        else
            printf("player cmd = %s\n", player->command[0]->cmd);
        player->command[0]->use_function(
            player,
            player->command[0]->args,
            info);
        if (player->time_start == ERROR_FIRST_COMMAND ||
        player->command[0]->end_function == NULL) {
            printf("first command then dequeue\n");
            player->time_start = READY_FIRST_COMMAND;
            dequeue_command(player);
            return (false);
        }
    }
    return (true);
}

/**
 * @brief function that executes the last given function
 * @param player a pointer to a structure corresponding to one player
 * @param info a pointer to a client structure containing all infos
 *  about the game
*/
void exec_end_func(player_t *player, info_t *info)
{
    double waiting = (clock() - player->time_start) / CLOCKS_PER_SEC;

    if (waiting >= (player->command[0]->time / info->freq)) {
        player->command[0]->end_function(
            player,
            player->command[0]->args,
            info);
        player->time_start = READY_FIRST_COMMAND;
        printf("second command then dequeue\n");
        dequeue_command(player);
    }
}

/**
 * @brief function that executes the command for the given player
 * @param player a pointer to a structure corresponding to one player
 * @param info a pointer to a client structure containing all infos
 *  about the game
*/
void exec_command_player(player_t *player, info_t *info)
{
    if (player->state != DEAD && player->command[0] != NULL) {
        if (!exec_first_func(player, info))
            return;
        if (player->command[0]->end_function != NULL &&
            strcmp(player->team_name, "GRAPHIC") != 0)
            exec_end_func(player, info);
    }
}

/**
 * @brief function that selects the functions corresponding to the
 *  given command
 * @param info a pointer to a client structure containing all infos
 *  about the game
*/
void exec_command(info_t *info)
{
    linked_player_t *tmp = info->head_player;

    gen_res_tick(info);
    while (tmp != NULL) {
        if (tmp->player.command[0] != NULL)
            exec_command_player(&tmp->player, info);
        if (strcmp(tmp->player.team_name, "GRAPHIC") &&
        tmp->player.state == ALIVE)
            eat(&tmp->player, info);
        tmp = tmp->next;
    }
}
