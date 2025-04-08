/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Argument handling for server
*/

/**
 * @file assign_command.c
 * @brief File containing functions that links different parameters
 *  to functions
*/

#include "../include/zappy_server.h"

/**
 * @brief function that calls different function for the gui
 * @param args an array that contains every arguments
 * @param client a pointer to a client structure for one client
*/
void gui_command_connection(char **args, client_t *client)
{
    for (size_t i = 0; GUI_COMMANDS[i].cmd; i++) {
        if (strcmp(GUI_COMMANDS[i].cmd, args[0]) == 0) {
            enqueue_command(client->player, args, &GUI_COMMANDS[i]);
            break;
        }
    }
}

/**
 * @brief function that calls different function for the AI
 * @param args an array that contains every arguments
 * @param client a pointer to a client structure for one client
*/
void player_command_connection(char **args, client_t *client)
{
    for (size_t i = 0; PLAYER_COMMANDS[i].cmd; i++) {
        if (strcmp(PLAYER_COMMANDS[i].cmd, args[0]) == 0) {
            enqueue_command(client->player, args, &PLAYER_COMMANDS[i]);
            break;
        }
    }
}

/**
 * @brief function that calls different function for the usage
 * @param args an array that contains every arguments
 * @param client a pointer to a client structure for one client
*/
void use_command(char **args, client_t *client)
{
    if (strcmp(client->player->team_name, "GRAPHIC") == 0)
        gui_command_connection(args, client);
    else
        player_command_connection(args, client);
}
