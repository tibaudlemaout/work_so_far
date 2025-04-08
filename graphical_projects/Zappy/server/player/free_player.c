/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file free_player.c
 * @brief File containing functions to free a player
*/

#include "../include/zappy_server.h"

/**
 * @brief function used to free one player and its structure
 * @param player a pointer to a structure for a player
*/
void free_player(player_t *player)
{
    for (int i = 0; player->command[i]; i++) {
        free_array(&player->command[i]->args);
        free(player->command[i]);
        player->command[i] = NULL;
    }
    free(player);
}

/**
 * @brief function used to free the linked list of every players
 * @param list a pointer to the linked list
*/
void destroy_players(linked_player_t *list)
{
    linked_player_t *tmp = list;
    linked_player_t *prev = NULL;

    while (tmp != NULL) {
        prev = tmp;
        tmp = tmp->next;
        free_player(&prev->player);
    }
}
