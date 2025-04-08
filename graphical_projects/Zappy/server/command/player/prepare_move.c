/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file prepare_move.c
 * @brief File containing a function for the preparation
 *  of a move for AI commands
*/

#include "../../include/zappy_server.h"

/**
 * @brief function that starts the forward AI command
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void start_forward(player_t *player, char **args, info_t *info)
{
    player_t temp = *player;
    char str[128];

    (void)args;
    set_time(player);
    forward(&temp, args, info);
    sprintf(str, "ppo %d %d %d %d\n", temp.id,
        temp.position.x, temp.position.y,
        temp.direction + 1);
    append_to_gui(info, str);
}

/**
 * @brief function that starts the right AI command
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void start_right(player_t *player, char **args, info_t *info)
{
    player_t temp = *player;
    char str[128];

    (void)args;
    set_time(player);
    right(&temp, args, info);
    sprintf(str, "ppo %d %d %d %d\n", temp.id,
        temp.position.x, temp.position.y,
        temp.direction + 1);
    append_to_gui(info, str);
}

/**
 * @brief function that starts the left AI command
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void start_left(player_t *player, char **args, info_t *info)
{
    player_t temp = *player;
    char str[128];

    (void)args;
    set_time(player);
    left(&temp, args, info);
    sprintf(str, "ppo %d %d %d %d\n", temp.id,
        temp.position.x, temp.position.y,
        temp.direction + 1);
    append_to_gui(info, str);
}
