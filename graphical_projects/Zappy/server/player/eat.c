/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file eat.c
 * @brief File containing a function for food consumption
*/

#include "../include/zappy_server.h"

/**
 * @brief function used for food consumption
 * @param player a pointer to a structure for a player
 * @param info a pointer to a structure containing every info about the game
*/
void eat(player_t *player, info_t *info)
{
    double waiting = (clock() - player->time_to_eat) / CLOCKS_PER_SEC;

    if (waiting >= (126 / info->freq)) {
        player->inventory.food--;
        if (player->inventory.food == 0) {
            player_death(player, NULL, info);
        } else
            player->time_to_eat = clock();
    }
}
