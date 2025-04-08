/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file verif_team.c
 * @brief File containing functions used for quick team verifications
*/

#include "../include/zappy_server.h"

/**
 * @brief function used to get the number of players in the linked list
 * @param head a pointer to the first player-element on the linked list
 * @param team_name the name of the team
 * @return the number of unused teams
*/
int get_nb_unused(linked_player_t *head, char *team_name)
{
    int i = 0;
    linked_player_t *tmp = head;

    while (tmp != NULL) {
        if (strcmp(tmp->player.team_name, team_name) == 0 &&
            tmp->player.state == UNUSED)
            i++;
        tmp = tmp->next;
    }
    return (i);
}

/**
 * @brief function used to know if a team is valid or no
 * @param name The name of the team to check
 * @param info a pointer to a structure with informations about the game
 * @return if the team is valid or not
*/
bool is_valid_team(char *name, info_t *info)
{
    for (int i = 0; i < info->nb_teams; i++) {
        if (strcmp(info->teams[i], name) == 0)
            return (true);
    }
    return (false);
}
