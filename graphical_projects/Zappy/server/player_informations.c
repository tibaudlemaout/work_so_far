/*
** EPITECH PROJECT, 2024
** zappytest
** File description:
** player_informations
*/

/**
 * @file player_informations.c
 * @brief Functions prototypes for AI commands
*/

#include <stdio.h>
#include "include/zappy_server.h"

/**
 * @brief function prototype for the AI to look around
 * @param str the string on which there are parameters
 * @param engine the old main game structure containing all informations
*/
void action_look_around(char *str, game_t *engine)
{
    printf("[tile1,tile2,...]\n");
}

/**
 * @brief function prototype for the AI to get inventory
 * @param str the string on which there are parameters
 * @param engine the old main game structure containing all informations
*/
void action_inventory(char *str, game_t *engine)
{
    printf("[material1 qte,material2 qte,...]\n");
}

/**
 * @brief function prototype for the AI to broadcast
 * @param str the string on which there are parameters
 * @param engine the old main game structure containing all informations
*/
void action_broadcast_text(char *str, game_t *engine)
{
    printf("ok\n");
}

/**
 * @brief function prototype for unknown str
 * @param str the string on which there are parameters
 * @param engine the old main game structure containing all informations
*/
void action_unknown(char *str, game_t *engine)
{
    printf("ko\n");
}
