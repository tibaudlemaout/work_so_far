/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file look_string_tools.c
 * @brief File containing different tools functions for the look AI command
*/

#include "../../include/zappy_server.h"

/**
 * @brief function that adds a comma up
 * @param player a pointer to a structure corresponding to a player
 * @param coords the wanted coordinates
 * @param i an iterator
 * @param n an iterator
*/
void add_coma_u(player_t *player, look_coords_t coords,
    int i, int n)
{
    if (i + 1 != coords.ly || n + 1 != coords.lx) {
        append_to_string(player->w_buffer, ",");
    }
}

/**
 * @brief function that adds a comma down
 * @param player a pointer to a structure corresponding to a player
 * @param coords the wanted coordinates
 * @param i an iterator
 * @param n an iterator
*/
void add_coma_d(player_t *player, look_coords_t coords,
    int i, int n)
{
    if (i - 1 != coords.ly || n - 1 != coords.lx) {
        append_to_string(player->w_buffer, ",");
    }
}

/**
 * @brief function that adds a comma to the left
 * @param player a pointer to a structure corresponding to a player
 * @param coords the wanted coordinates
 * @param i an iterator
 * @param n an iterator
*/
void add_coma_l(player_t *player, look_coords_t coords,
    int i, int n)
{
    if (i - 1 != coords.lx || n + 1 != coords.ly) {
        append_to_string(player->w_buffer, ",");
    }
}

/**
 * @brief function that adds a comma to the right
 * @param player a pointer to a structure corresponding to a player
 * @param coords the wanted coordinates
 * @param i an iterator
 * @param n an iterator
*/
void add_coma_r(player_t *player, look_coords_t coords,
    int i, int n)
{
    if (i + 1 != coords.lx || n - 1 != coords.ly) {
        append_to_string(player->w_buffer, ",");
    }
}
