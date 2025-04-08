/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file incantation.c
 * @brief File containing functions for the incantation AI command
*/

#include "../../include/zappy_server.h"

const int player_tab[] = {1, 2, 2, 4, 4, 6, 6};
const int linemate_tab[] = {1, 1, 2, 1, 1, 1, 2};
const int deraumere_tab[] = {0, 1, 0, 1, 2, 2, 2};
const int sibur_tab[] = {0, 1, 1, 2, 1, 3, 2};
const int mendiane_tab[] = {0, 0, 0, 0, 3, 0, 2};
const int phiras_tab[] = {0, 0, 2, 1, 0, 1, 2};
const int thystame_tab[] = {0, 0, 0, 0, 0, 0, 1};

/**
 * @brief function that returns the number of players in one single tile
 * @param info a pointer to a structure containing every game info
 * @param coords the coordinates of the wanted tile
 * @param lvl the wanted level of the players
*/
int nb_player_inxy(info_t *info, position_t coords, int lvl)
{
    int i = 0;
    linked_player_t *tmp = info->head_player;

    (void)GUI_COMMANDS;
    while (tmp != NULL) {
        if (tmp->player.position.x == coords.x &&
            tmp->player.position.y == coords.y &&
            tmp->player.level == lvl)
            i++;
        tmp = tmp->next;
    }
    return (i);
}

/**
 * @brief function that checks if the incantation is possible AI command
 * @param player a pointer to a structure corresponding to a player
 * @param info a pointer to a structure containing every game info
 * @return if the incantation is possible or not
*/
bool check_incantation(player_t *player, info_t *info)
{
    inventory_t inv = info->map.tile[player->position.y][player->position.x];
    int linemate_nb = linemate_tab[player->level - 1];
    int deraumere_nb = deraumere_tab[player->level - 1];
    int sibur_nb = sibur_tab[player->level - 1];
    int mendiane_nb = mendiane_tab[player->level - 1];
    int phiras_nb = phiras_tab[player->level - 1];
    int thystame_nb = thystame_tab[player->level - 1];
    int player_nb = player_tab[player->level - 1];

    if (has_x_ressource(inv, LINEMATE, linemate_nb) &&
        has_x_ressource(inv, DERAUMERE, deraumere_nb) &&
        has_x_ressource(inv, SIBUR, sibur_nb) &&
        has_x_ressource(inv, MENDIANE, mendiane_nb) &&
        has_x_ressource(inv, PHIRAS, phiras_nb) &&
        has_x_ressource(inv, THYSTAME, thystame_nb) &&
        nb_player_inxy(info, player->position, player->level)
        >= player_nb) {
        return (true);
    } else
        return (false);
}

/**
 * @brief function that launches all the incantations AI command
 * @param player a pointer to a structure corresponding to a player
 * @param info a pointer to a structure containing every game info
*/
void launch_all_incantations(player_t *player, info_t *info)
{
    char str_gui[48];
    linked_player_t *tmp = info->head_player;

    while (tmp != NULL) {
        if (tmp->player.position.x == player->position.x &&
            tmp->player.position.y == player->position.y &&
            tmp->player.level == player->level &&
            tmp->player.state == ALIVE &&
            tmp->player.id != player->id &&
            tmp->player.time_start == READY_FIRST_COMMAND) {
            append_to_string(tmp->player.w_buffer, "Elevation underway\n");
            enqueue_command_front(&tmp->player, NULL, &PLAYER_COMMANDS[13]);
            set_time(&tmp->player);
            sprintf(str_gui, " %d", tmp->player.id);
            append_to_gui(info, str_gui);
        }
        tmp = tmp->next;
    }
}

/**
 * @brief function that starts the incantation AI command
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void start_incantation(player_t *player, char **args, info_t *info)
{
    char str_gui[48];

    (void)args;
    if (check_incantation(player, info)) {
        set_time(player);
        append_to_string(player->w_buffer, "Elevation underway\n");
        sprintf(str_gui, "pic %d %d %d %d", player->position.x,
            player->position.y, player->level, player->id);
        append_to_gui(info, str_gui);
        launch_all_incantations(player, info);
        append_to_gui(info, "\n");
    } else {
        append_to_string(player->w_buffer, "ko\n");
        player->time_start = ERROR_FIRST_COMMAND;
    }
}
