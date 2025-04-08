/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file assign_gui.c
 * @brief File containing a function that concatenates a string in
 *  the main structure for gui
*/

#include "../include/zappy_server.h"

/**
 * @brief function that concatenates a string in the main structure for gui
 * @param info pointer to a structure containing all infos about the game
 * @param str a string to put on the structure
*/
void append_to_gui(info_t *info, char *str)
{
    linked_player_t *tmp = info->head_player;

    while (tmp != NULL) {
        if (tmp->player.state == ALIVE &&
            strcmp(tmp->player.team_name, "GRAPHIC") == 0)
            append_to_string(tmp->player.w_buffer, str);
        tmp = tmp->next;
    }
}
