/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** map creation
*/

/**
 * @file player_nb.c
 * @brief File containing a function returning the number of
 *  players on given tile
*/

#include "include/zappy_server.h"

/**
 * @brief Function that returns the number of players on a given tile
 * @param info pointer to a structure containing all informations
 *  about the game
 * @param coords as a structure, contains the coordinates of the tile we want
 * @return an integer containing the number of players on the given tile
*/
int get_nb_players(info_t *info, position_t coords)
{
    int i = 0;
    linked_player_t *tmp = info->head_player;

    while (tmp != NULL) {
        if (tmp->player.position.x == coords.x &&
            tmp->player.position.y == coords.y)
            i++;
        tmp = tmp->next;
    }
    return (i);
}
