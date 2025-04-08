/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Argument handling for server
*/

/**
 * @file command_queue.c
 * @brief File containing functions for command queue and storage
*/

#include "../include/zappy_server.h"

/**
 * @brief function that initiates a command
 * @param player a pointer to a structure corresponding to one player
 * @param args an array containing every arguments for the command
 * @param command a pointer to a command structure corresponding to a command
 * @param i an integer corresponding to the index of the command
*/
void init_command(player_t *player, char **args, command_t *command, int i)
{
    int j = 0;

    if (!player->command[0]) {
        player->command[0] = malloc(sizeof(*player->command[0]));
        player->command[0]->cmd = command->cmd;
        player->command[0]->use_function = command->use_function;
        player->command[0]->end_function = command->end_function;
        player->command[0]->time = command->time;
    }
    player->command[0]->args = malloc(sizeof(char *) * (count_args(args) + 1));
    if (player->command[i]->args == NULL)
        show_error("error command args malloc\n");
    if (args) {
        for (j = 0; args[j]; j++)
            player->command[i]->args[j] = strdup(args[j]);
    }
    player->command[i]->args[j] = NULL;
}

/**
 * @brief function that gives the front command of the queue
 * @param player a pointer to a structure corresponding to one player
 * @param args an array containing every arguments for the command
 * @param command a pointer to a command structure corresponding to a command
*/
void enqueue_command_front(player_t *player, char **args, command_t *command)
{
    int i = 0;

    for (i = 0; player->command[i]; i++);
    for (; i != 0; i--) {
        if (i == MAX_COMMAND - 1) {
            free(player->command[i]);
            player->command[i] = NULL;
        }
        player->command[i] = player->command[i - 1];
    }
    init_command(player, args, command, i);
}

/**
 * @brief function that puts commands in the queue
 * @param player a pointer to a structure corresponding to one player
 * @param args an array containing every arguments for the command
 * @param command a pointer to a command structure corresponding to a command
*/
void enqueue_command(player_t *player, char **args, command_t *command)
{
    int i = 0;
    int j = 0;
    int nb_args = count_args(args);

    for (i = 0; player->command[i]; i++);
    if (i >= MAX_COMMAND)
        return;
    if (!player->command[i]) {
        player->command[i] = malloc(sizeof(*player->command[i]));
        player->command[i]->cmd = strdup(command->cmd);
        player->command[i]->use_function = command->use_function;
        player->command[i]->end_function = command->end_function;
        player->command[i]->time = command->time;
    }
    player->command[i]->args = malloc(sizeof(char *) * (nb_args + 1));
    if (player->command[i]->args == NULL)
        show_error("error command malloc\n");
    for (j = 0; args[j]; j++)
        player->command[i]->args[j] = strdup(args[j]);
    player->command[i]->args[j] = NULL;
}

/**
 * @brief function that manages the queue for commands and by player
 * @param player a pointer to a structure corresponding to one player
*/
void dequeue_command(player_t *player)
{
    if (!player->command[0])
        return;
    if (player->command[0]->args)
        free_array(&(player->command[0]->args));
    free(player->command[0]);
    for (int i = 0; player->command[i]; i++) {
        if (i == MAX_COMMAND - 1) {
            player->command[i] = NULL;
            break;
        }
        player->command[i] = player->command[i + 1];
    }
}
