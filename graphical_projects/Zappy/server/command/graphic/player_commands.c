/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file player_commands.c
 * @brief File containing functions to send to the gui for the player
*/

#include "../../include/zappy_server.h"

/**
 * @brief function that sends to the gui the position of the player
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void player_pos(player_t *player, char **args, info_t *info)
{
    int n = atoi(args[1]);
    char str[16];
    linked_player_t *tmp = info->head_player;

    (void)player;
    while (tmp != NULL) {
        if (tmp->player.id == n) {
            sprintf(str, "ppo %d %d %d %d\n", n, tmp->player.position.x,
                tmp->player.position.y,
                tmp->player.direction + 1);
            append_to_gui(info, str);
            break;
        }
        tmp = tmp->next;
    }
}

/**
 * @brief function that sends to the gui the level of the player
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void player_lvl(player_t *player, char **args, info_t *info)
{
    int n = atoi(args[1]);
    char str[16];
    linked_player_t *tmp = info->head_player;

    (void)player;
    while (tmp != NULL) {
        if (tmp->player.id == n) {
            sprintf(str, "plv %d %d\n", n, tmp->player.level);
            append_to_gui(info, str);
            break;
        }
        tmp = tmp->next;
    }
}

/**
 * @brief function that sends to the gui the inventory of the player
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void player_inv(player_t *player, char **args, info_t *info)
{
    int n = atoi(args[1]);
    char str[48];
    linked_player_t *tmp = info->head_player;

    (void)player;
    while (tmp != NULL) {
        if (tmp->player.id == n) {
            sprintf(str, "pin %d %d %d %d %d %d %d %d\n", n,
                tmp->player.inventory.food, tmp->player.inventory.linemate,
                tmp->player.inventory.deraumere, tmp->player.inventory.sibur,
                tmp->player.inventory.mendiane,
                tmp->player.inventory.phiras,
                tmp->player.inventory.thystame);
            append_to_gui(info, str);
            break;
        }
        tmp = tmp->next;
    }
}
