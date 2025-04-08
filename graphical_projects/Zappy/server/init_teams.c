/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** initialization of the server
*/

/**
 * @file init_teams.c
 * @brief File containing functions for teams initialization
*/

#include "include/zappy_server.h"

/**
 * @brief Function that fills a team based on the program arguments
 * @param i integer corresponding to the team number
 * @param argc integer containing the number of arguments
 * @param argv array containing every arguments, containing team names
 * @param data pointer to a structure containing every information
 *  about the game (to be initialized)
*/
static void fill_teams(int i, const int argc, const char **argv, info_t *data)
{
    for (i = i + 1; i < argc && argv[i] && argv[i][0] != '-'; i++) {
        data->teams = realloc(data->teams,
        sizeof(char *) * (data->nb_teams + 1));
        if (data->teams == NULL)
            show_error("fill team realloc fail.");
        data->teams[data->nb_teams] = strdup(argv[i]);
        data->nb_teams++;
    }
    return;
}

/**
 * @brief Main function used for teams initializations, based on
 *  program arguments
 * @param argc integer containing the number of arguments
 * @param argv array containing every arguments, containing team names
 * @param data pointer to a structure containing every information
 *  about the game (to be initialized)
*/
void init_teams(const int argc, const char **argv, info_t *data)
{
    int i = 0;

    while (i != argc) {
        if (strcmp(argv[i], "-n") == 0)
            break;
        i++;
    }
    data->teams = malloc(sizeof(char *) * 2);
    if (data->teams == NULL)
        show_error("team names malloc fail\n");
    data->nb_teams = 0;
    fill_teams(i, argc, argv, data);
    if (data->nb_teams < 2)
        show_error("not enough teams(min 2)\n");
    data->teams = realloc(data->teams,
    sizeof(char *) * (data->nb_teams + 1));
    if (data->teams == NULL)
        show_error("team name realloc fail\n");
    data->teams[data->nb_teams] = NULL;
    return;
}
